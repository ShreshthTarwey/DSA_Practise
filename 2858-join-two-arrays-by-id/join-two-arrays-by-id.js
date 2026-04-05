/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    let result = [];
    let i=0;
    let j=0;
    arr1.sort((a,b)=>a.id-b.id);
    arr2.sort((a,b)=>a.id-b.id);
    while(i<arr1.length && j<arr2.length){
        if(arr1[i].id<arr2[j].id){
            result.push(arr1[i++]);
        }
        else if(arr1[i].id>arr2[j].id){
            result.push(arr2[j++]);
        }
        else{
            result.push({...arr1[i++], ...arr2[j++]});
        }
    }
    while(i<arr1.length){
        result.push(arr1[i++]);
    }
    while(j<arr2.length){
        result.push(arr2[j++]);
    }
    return result;
};