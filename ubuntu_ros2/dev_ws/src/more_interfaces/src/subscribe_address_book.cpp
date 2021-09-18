#include <functional>
#include <memory>

#include "more_interfaces/msg/address_book.hpp"
#include "rclcpp/rclcpp.hpp"

using std::placeholders::_1;

class AddressSubscriber : public rclcpp::Node {
 public:
  AddressSubscriber() : Node("address_subscriber") {
    subscription_ =
        this->create_subscription<more_interfaces::msg::AddressBook>(
            "address_book", 10,
            std::bind(&AddressSubscriber::topic_callback, this, _1));
  }

 private:
  void topic_callback(const more_interfaces::msg::AddressBook::SharedPtr msg) {
    RCLCPP_INFO(this->get_logger(), "I got name: %s %s age: %d",
                msg->first_name.c_str(), msg->last_name.c_str(), msg->age);
  }

  rclcpp::Subscription<more_interfaces::msg::AddressBook>::SharedPtr
      subscription_;
};

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<AddressSubscriber>());
  rclcpp::shutdown();
}