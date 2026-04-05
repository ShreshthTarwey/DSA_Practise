/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */

var recFun = function (arr, depth, n, res){
    for(let i=0;i<arr.length;i++){
        if(Array.isArray(arr[i]) && depth<n){
            recFun(arr[i], depth+1, n, res);
        }
        else{
            res.push(arr[i]);
        }
    }
}
var flat = function (arr, n) {
    let res = [];
    recFun(arr, 0, n, res);
    return res;
};