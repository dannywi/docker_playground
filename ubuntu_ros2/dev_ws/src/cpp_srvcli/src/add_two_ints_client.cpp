#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"
#include "tutorial_interfaces/srv/add_three_ints.hpp"

#include <chrono>
#include <cstdlib>
#include <memory>

using namespace std::chrono_literals;
namespace wv {

  template <typename IF>
  class Client {
    using REQUEST = typename IF::Request;
  public:
    Client(std::shared_ptr<rclcpp::Node> node) : node_(node) {}

    void sendRequest(long int a, long int b, long int c) {
      //std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("add_three_ints_client");
      auto client = node_->create_client<IF>("add_three_ints");
      auto request = std::make_shared<REQUEST>();
      request->a = a;
      request->b = b;
      request->c = c;

      sendRequestCommon(client, request);
    }

    void sendRequest(long int a, long int b) {
      auto client = node_->create_client<IF>("add_two_ints");
      auto request = std::make_shared<REQUEST>();
      request->a = a;
      request->b = b;

      sendRequestCommon(client, request);
    }

  private:
    template<typename CLIENT_PTR, typename REQ_PTR>
    void sendRequestCommon(CLIENT_PTR client, REQ_PTR request) {
      while (!client->wait_for_service(1s)) {
        if (!rclcpp::ok()) {
          RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
          return;
        }
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
      }

      auto result = client->async_send_request(request);
      // Wait for the result.
      if (rclcpp::spin_until_future_complete(node_, result) ==
        rclcpp::FutureReturnCode::SUCCESS)
      {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Sum: %ld", result.get()->sum);
      } else {
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service ....");
      }
    }

  private:
    std::shared_ptr<rclcpp::Node> node_;
  };

}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  if (!(argc == 3 || argc == 4)) {
      RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "usage: add_two_ints_client X Y OR add_three_ints_client X Y Z");
      return 1;
  }

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("add_two_ints_client");

  if (argc == 4) {
    wv::Client<tutorial_interfaces::srv::AddThreeInts> c3(node);
    c3.sendRequest(atoll(argv[1]), atoll(argv[2]), atoll(argv[3]));
  } else if(argc == 3) {
    wv::Client<example_interfaces::srv::AddTwoInts> c2(node);
    c2.sendRequest(atoll(argv[1]), atoll(argv[2]));
  }

  rclcpp::shutdown();
  return 0;
}
