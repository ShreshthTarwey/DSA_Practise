class EventEmitter {
    
    /**
     * @param {string} eventName
     * @param {Function} callback
     * @return {Object}
     */
    
    constructor(){
        this.events = new Map();
    }

    subscribe(eventName, callback) {
        if(!this.events.has(eventName)){
            this.events.set(eventName, []);
        }
        let listners = this.events.get(eventName);
        listners.push(callback);
        return {
            unsubscribe: () => {
                let currentListners = this.events.get(eventName);
                const index = currentListners.indexOf(callback);
                if(index!=-1){
                    currentListners.splice(index, 1);
                }
            }
        };
    }
    
    /**
     * @param {string} eventName
     * @param {Array} args
     * @return {Array}
     */
    emit(eventName, args = []) {
        if(!this.events.has(eventName)){
            return [];
        }

        return this.events.get(eventName).map((cb) => cb(...args));
    }
}

/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */