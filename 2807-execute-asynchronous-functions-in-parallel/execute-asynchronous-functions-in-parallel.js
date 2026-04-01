/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
    let result = [];
    let counter = 0;
    return new Promise((resolve, reject)=>{
        functions.forEach((fn, i)=>{
            fn()
            .then(val=>{
                result[i] = val;
                counter++;
                if(counter === functions.length){
                    resolve(result);
                }
            })
            .catch(err=>{
                reject(err);
            })
        });
    });
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */