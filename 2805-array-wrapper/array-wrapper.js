/**
 * @param {number[]} nums
 * @return {void}
 */
var ArrayWrapper = function(nums) {
    this.nums = nums;
};

/**
 * @return {number}
 */
ArrayWrapper.prototype.valueOf = function() {
    return this.nums.reduce((sum, current)=>(
        sum + current
    ), 0);
}

/**
 * @return {string}
 */
ArrayWrapper.prototype.toString = function() {
    let str = "[";
    for(let i=0;i<this.nums.length;i++){
        str += this.nums[i];
        if(i!==this.nums.length-1){
            str += ",";
        }
    }
    str += ']';
    return str;
}

/**
 * const obj1 = new ArrayWrapper([1,2]);
 * const obj2 = new ArrayWrapper([3,4]);
 * obj1 + obj2; // 10
 * String(obj1); // "[1,2]"
 * String(obj2); // "[3,4]"
 */