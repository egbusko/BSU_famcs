const alphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
// Шифр простой замены. Расшифровать -> зашифровать
const input1 = "ЩМЁУТНБД";
const key = "ИЮЧЪЩЁЗМШСХУРЦЭЬЫНФДБТВЛГАПЯЕОЖКЙ";
let result = '';
let resultReverse = '';

for (letter of input1) {
    result += alphabet[key.indexOf(letter)];
}
for (letter of result) {
    resultReverse += key[alphabet.indexOf(letter)];
}

console.log(input1, " -> ", result, " -> ", resultReverse);

result = '';
resultReverse = '';
// Афинный шифр. Зашифровка и расшифровка
const input2 = "КРИПТОСИСТЕМА";
const a = 17, b = 24;

for (letter of input2) {
    result += alphabet[(alphabet.indexOf(letter) * a + b) % alphabet.length];
}
for (letter of result) {
    resultReverse += alphabet[((alphabet.indexOf(letter) + alphabet.length - b) * 2) % alphabet.length];
}
console.log(input2, " -> ", result, " -> ", resultReverse);
