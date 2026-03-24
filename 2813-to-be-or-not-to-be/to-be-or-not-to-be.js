/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    let obj = {
        toBe: function (val2){
            if(val2!==val){
                throw new Error("Not Equal");
            }
            return true;
        },

        notToBe: function(val2){
            if(val2 === val){
                throw new Error("Equal");
            }
            return true;
        }
    }
    return obj;
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */