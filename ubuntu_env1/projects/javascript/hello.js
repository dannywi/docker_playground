let name = "World";
name = -1/0 == -Infinity;
console.log(`Hello ${name}!`);

let one;
let two = "two";
let thr = "thr";
//let val1 = (one ?? two ?? thr ?? "NO VAL");
let val2 = (one || two || thr || "NO VAL");
//console.log(val1);
console.log(val2);

function tmp() {
    return [2, 3];
}

let [a, b] = tmp();
console.log(a);
console.log(b);

let codes = {
    "+49": "Germany",
    "+44": "UK",
};

for(let c in codes) {
    console.log("----");
    console.log(+c);
    console.log(codes[c]);
}

let sayHi = (phrase, who) => console.log(phrase + ", " + who);
let timerId = setTimeout(sayHi, 1000, "Hi", "John");

console.log("timerId", timerId);

timerId = setInterval(sayHi, 1000, "Hello", "Jane");
setTimeout(() => clearInterval(timerId), 3000);
