#include "unordered_array_set.h"
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

void unordered_array_set_isAbleAppend(unordered_array_set *set) {
    assert(set->size < set->capacity);
}

unordered_array_set unordered_array_set_create(size_t capacity) {
    return (unordered_array_set) {
            malloc(sizeof(int) * capacity),
            0,
            capacity
    };
}

size_t unordered_array_set_in(unordered_array_set *set, int value) {
    for (size_t i = 0; i < set->size; i++)
        if (set->data[i] == value)
            return i;

    return set->size;
}


int unordered_array_set_isSubset(unordered_array_set subset, unordered_array_set set) {
    if (set.size < subset.size)
        return 0;
    for (int i = 0; i < subset.size; i++)
        if (unordered_array_set_in(&set, subset.data[i]) == set.size)
            return 0;
    return 1;
}

void unordered_array_set_insert(unordered_array_set *set, int x) {
    unordered_array_set_isAbleAppend(set);
    if (unordered_array_set_in(set, x) == set->size)
        append_(set->data, &(set->size), x);
}

unordered_array_set unordered_array_set_create_from_array(const int *a, size_t size) {
    unordered_array_set set = unordered_array_set_create(size);
    for (size_t i = 0; i < size; i++)
        unordered_array_set_insert(&set, a[i]);

    return set;
}

void unordered_array_set_deleteElement(unordered_array_set *set, int value) {
    size_t indexDelete = unordered_array_set_in(set, value);
    if (indexDelete != set->size)
        deleteByPosUnsaveOrder_(set->data, &set->size, indexDelete);
}

bool unordered_array_set_isEqual(unordered_array_set set1, unordered_array_set set2) {
    if (set1.size != set2.size)
        return false;

    for (size_t i = 0; i < set1.size; i++) {
        if (unordered_array_set_in(&set2, set1.data[i]) == set2.size)
            return false;
    }
    return true;
}

void unordered_array_set_printf(unordered_array_set set) {
    printf("{");
    bool isEmpty = true;
    for (size_t i = 0; i < set.size; i++) {
        printf("%d, ", set.data[i]);
        isEmpty = false;
    }
    if (isEmpty)
        printf("}");
    else
        printf("\b\b}\n");
}

unordered_array_set unordered_array_set_union(unordered_array_set set1, unordered_array_set set2) {
    size_t capacity = set1.size + set2.size;

    unordered_array_set set3 = unordered_array_set_create(capacity);
    for (size_t i = 0; i < set1.size; i++)
        unordered_array_set_insert(&set3, set1.data[i]);

    for (size_t i = 0; i < set2.size; i++)
        unordered_array_set_insert(&set3, set2.data[i]);
    return (unordered_array_set) set3;
}

unordered_array_set unordered_array_set_intersection(unordered_array_set set1, unordered_array_set set2) {
    size_t capacity = set1.size + set2.size;
    unordered_array_set set3 = unordered_array_set_create(capacity);

    for (size_t i = 0; i < set1.size; i++)
        if (unordered_array_set_in(&set2, set1.data[i]) != set2.size)
            unordered_array_set_insert(&set3, set1.data[i]);

    return (unordered_array_set) set3;
}

unordered_array_set unordered_array_set_difference(unordered_array_set set1, unordered_array_set set2) {
    size_t capacity = set1.size + set2.size;

    unordered_array_set set3 = unordered_array_set_create(capacity);
    for (size_t i = 0; i < set1.size; i++)
        unordered_array_set_insert(&set3, set1.data[i]);

    for (size_t i = 0; i < set2.size; i++)
        if (unordered_array_set_in(&set3, set2.data[i]) != set3.size) {
            unordered_array_set_deleteElement(&set3, set2.data[i]);
        }

    return (unordered_array_set) set3;
}

unordered_array_set unordered_array_set_symmetricDifference(unordered_array_set set1,
                                                                    unordered_array_set set2) {
    unordered_array_set set3 = unordered_array_set_union(unordered_array_set_difference(set1, set2),
                                                                 unordered_array_set_difference(set2, set1));

    return (unordered_array_set) set3;
}

unordered_array_set unordered_array_set_complement(unordered_array_set set, unordered_array_set universumSet) {
    return (unordered_array_set) unordered_array_set_difference(universumSet, set);
}

void unordered_array_set_delete(unordered_array_set set) {
    free(set.data);
}
