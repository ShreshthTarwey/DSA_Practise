/**
 * @param {Object|Array} obj
 * @return {boolean}
 */
var isEmpty = function(obj) {
    for(keys in obj){
        return false;
    }
    return true;
    // return Object.keys(obj).length === 0;
};