/**
 * @param {number} n
 * @return {number[]}
 */
var lexicalOrder = function (n) {
    let arr = [];
    for (var i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    arr.sort();
    return arr;
};

//javascript normal sort works here 