/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let counter = init;
    let obj = {
        increment: function(){
            return ++counter;
        },

        decrement: function(){
            return --counter;
        },
        reset: function(){
            counter = init;
            return counter;
        }
    }
    return obj;
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */