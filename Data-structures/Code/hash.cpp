#include <iostream>
#include <string>


typedef struct hashItems* pHashItems;

typedef struct hashItems {
    std::string key;
    std::string value;
    pHashItems nextHashItem;
    int isEmpty;

}hashItems;

int table_size;

hashItems hashTable1[100];
hashItems hashTable2[100];


hashItems newHashItem (std::string key, std::string value) {
    hashItems item;
    item.key = key;
    item.value = value;
    item.isEmpty = 1;
    item.nextHashItem = NULL;
    
    return item;
}


int getHashCode(std::string key) {
    int hashCode = 0;
    for (int i = 0; i < key.length(); i++)
        hashCode += key[i];

    return hashCode;
}

int convertToIndex(int key) {
    return key % table_size;
}




void chaining_put(std::string key, std::string value) {
    int hashCode = getHashCode(key);
    int hashArrayIndex = convertToIndex(hashCode);

    hashItems item = newHashItem(key, value);

    if (hashTable1[hashArrayIndex].isEmpty == 0) {
        //hash table의 슬롯이 비어 있으면 바로 삽입

        hashTable1[hashArrayIndex] = item;
        std::cout << "hashTable[" << hashArrayIndex << "] " << "\n";
        std::cout << " - key: " << hashTable1[hashArrayIndex].key << "\n";
        std::cout << " - value: " << hashTable1[hashArrayIndex].value << "\n\n";


    } 
    
    else {
        //hash table의 슬롯이 비어있지 않으면
        std::cout << "hashTable[" << hashArrayIndex << "], " << key << "에서 해시충돌 발생!" << "\n";
        
        //hash table 슬롯에 저장된 첫번째 데이터를 가져온다.
        hashItems hashItem = hashTable1[hashArrayIndex]; 
        
        // 연결리스트 마지막까지 탐색을 수행하고 삽입.

        while (hashItem.nextHashItem != NULL) {
            std::cout << " ?";
            hashItem = *(hashItem.nextHashItem);

        }

        hashItem.nextHashItem = &item;

        std::cout << "hashTable[" << hashArrayIndex << "]의 연결리스트 뒤에 연결되었습니다." << "\n\n";

    }

}

std::string chaining_get(std::string key) {
        int hashCode = getHashCode(key);
        int hashArrayIndex = convertToIndex(hashCode);

        if (hashTable1[hashArrayIndex].isEmpty == 0) return "not found";

        hashItems hashItem = hashTable1[hashArrayIndex];


        while (hashItem.isEmpty != 1 && hashItem.key != key) {
            hashItem = *(hashItem.nextHashItem);
        }


        if (hashItem.isEmpty == 0) return "not found";
        else return hashItem.value;

}

void openadd_put(int key, int value) {
       //충돌을 발생하기 위해서 key값을 hashcode로 바로 사용
       //key값이 1, 11, 21 ..이 들어오면 충돌 발생 
        int hashArrayIndex = convertToIndex(key); 
        std::cout << "chaining_put() method called with value : " + value << ", hashArrayIndex : " + hashArrayIndex << "\n";

        //충돌이 없을 때까지 반복 수행
        while (hashTable2[hashArrayIndex].isEmpty != 0) {
            //인덱스 1 씩 증가
            hashArrayIndex = (hashArrayIndex + 1) % table_size;
            std::cout << "collision -> move to next index : " + hashArrayIndex << "\n";
        }
        std::cout << "Inserted finally with index : " + hashArrayIndex << "\n";
        hashTable2[hashArrayIndex] = newHashItem(std::to_string(key), std::to_string(value));

    }

int openadd_get(int key) {
        int hashArrayIndex = convertToIndex(key);

        while (hashTable2[hashArrayIndex].isEmpty != 0 && hashTable2[hashArrayIndex].key != std::to_string(key)) {
            hashArrayIndex = (hashArrayIndex + 1) % table_size;
            std::cout << "not matched, move to next index : " + hashArrayIndex << "\n";

        }

        if (hashTable2[hashArrayIndex].isEmpty == 0) return -1;
        else return std::stoi(hashTable2[hashArrayIndex].value);
    }








int main() {
    std::cin >> table_size;

    std::cout << "----------------Chaining HashTable-------------------" << "\n";
    chaining_put("key1", "a");
    chaining_put("key2", "ab");
    chaining_put("key3", "abc");
    chaining_put("key4", "abcd");
    chaining_put("key5", "abcde");
    chaining_put("key6", "abcde");
    chaining_put("key7", "abcde");
    chaining_put("key8", "abcde");
    chaining_put("key9", "abcde");
    chaining_put("key10", "abcde");
    chaining_put("key11", "abcde");
    chaining_put("key12", "abcde");
    chaining_put("key13", "abcde");

    std::cout << "key1의 value : " + chaining_get("key1") << "\n";
    std::cout << "key6의 value : " + chaining_get("key6") << "\n";

    std::cout << "--------------Linear Probing HashTable-----------------" << "\n";

    openadd_put(1,10);
    openadd_put(2,20);
    openadd_put(11,100); //충돌 발생
    std::cout << "key1의 value : " + openadd_get(1) << "\n";
    std::cout << "key2의 value : " + openadd_get(2) << "\n";

    return 0;

}
