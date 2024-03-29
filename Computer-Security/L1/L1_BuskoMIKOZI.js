const alphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"
const n = alphabet.length
const ksi_n = 20  //если n 33


// Шифр Виженера. Зашифровать и расшифровать
// работает для любых input и key (где key <= input)
const input1 = "ШИФРТЕКСТ"
const key1 = "ИЕЮ"
var key2 = key1
let encr1 = ''
let decr1 = ''

var i = 0;
while (key2.length < input1.length) {
    key2 += key1[i++]
    if (i == 3) {
        i = 0;
    }
}
//console.log(key2)


let x_i = '', l_i = '', y_i = '';
for (let i = 0; i < input1.length; i++) {
    x_i = alphabet.indexOf(input1[i])
    l_i = alphabet.indexOf(key2[i])
    encr1 += alphabet[(x_i + l_i) % n];
}

for (let i = 0; i < input1.length; i++) {
    y_i = alphabet.indexOf(encr1[i])
    l_i = alphabet.indexOf(key2[i])
    if ((y_i - l_i) < 0) {
        decr1 += alphabet[(y_i - l_i + n) % n]
    }
    else {
        decr1 += alphabet[(y_i - l_i) % n]
    }
}

console.log('\n---Vigenere---\nInput:', input1, "\nEncrypted:", encr1, "\nDecrypted:", decr1);





// Шифр Хилла. Расшифровать и зашифровать
// Работает для любых строк длины кратных 2 и ключей в виде матриц 2*2
// также detA^-1 считался отдельно
const input2 = "ВКУРДХГЁ";
const a = [[16, 29], [1, 22]];

let a_1 = [[0, 0], [0, 0]];
let decr2 = '';
let encr2 = '';
let tmp = 0;

let detA = a[0][0] * a[1][1] - a[0][1] * a[1][0];
while (detA < 0) {
    detA += n;
}
let detA_1 = 14 //Math.pow(detA, ksi_n - 1) % n

a_1[0][0] = (detA_1 * (a[1][1] % n)) % n
a_1[0][1] = (detA_1 * ((n - a[0][1]) % n)) % n
a_1[1][0] = (detA_1 * ((n - a[1][0]) % n)) % n
a_1[1][1] = (detA_1 * (a[0][0] % n)) % n

for (let i = 0; i < input2.length; i += 2) {
    tmp = (alphabet.indexOf(input2[i]) * a_1[0][0]) % n + (alphabet.indexOf(input2[i + 1]) * a_1[1][0]) % n;
    decr2 += alphabet[tmp % n]
    tmp = (alphabet.indexOf(input2[i]) * a_1[0][1]) % n + (alphabet.indexOf(input2[i + 1]) * a_1[1][1]) % n;
    decr2 += alphabet[tmp % n]
}

for (let i = 0; i < input2.length; i += 2) {
    tmp = alphabet.indexOf(decr2[i]) * a[0][0] + alphabet.indexOf(decr2[i + 1]) * a[1][0];
    encr2 += alphabet[tmp % n]
    tmp = alphabet.indexOf(decr2[i]) * a[0][1] + alphabet.indexOf(decr2[i + 1]) * a[1][1];
    encr2 += alphabet[tmp % n]
}

console.log('\n\n---Hill---\nInput:', input2, "\nDecrypted:", decr2, "\nEncrypted:", encr2);