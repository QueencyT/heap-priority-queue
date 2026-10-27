
# Max Heap & Priority Queue

## Overview

Max Heap & Priority Queue is a custom, template-based implementation developed from scratch in C++, supporting priority-based insertion, removal, and ordered processing of elements.

The project implements a Max Heap using an array-based binary tree, where parent nodes maintain higher priority than their children. A Priority Queue is built on top of this structure, associating each element with a priority value and an insertion timestamp.

**Unlike a conventional priority queue that may process equal-priority elements in an unspecified order, this implementation uses timestamps to preserve first-in, first-out (FIFO) ordering among elements with equal priorities.**

---

## Key Features

- **Template-Based Implementation:** Supports multiple data types through C++ templates.
- **Array-Based Max Heap:** Stores elements in a fixed-capacity array representing a complete binary tree.
- **Priority-Based Processing:** Removes the highest-priority element first.
- **FIFO Tie-Breaking:** Preserves insertion order among elements with equal priorities.
- **Heap Reordering:** Uses upward and downward element movement to maintain heap ordering.
- **Custom Comparison Operators:** Compares elements based on priority and insertion timestamp.
- **Heap Validation:** Recursively verifies the parent-child heap ordering property.
- **Tree Visualization:** Displays the heap's hierarchical structure for debugging.
- **GoogleTest Integration:** Includes test programs for heap operations and priority queue behavior.

---

## System Architecture

The project consists of three primary components: the Max Heap, the Priority Queue, and a custom structure for storing priority information.

### 1. <ins>Max Heap Implementation</ins>

The `Heap<T>` class implements a Max Heap using a fixed-capacity array.

```cpp
static const int CAPACITY = 1000;
T _heap[CAPACITY];
int _how_many;
```

Instead of dynamically allocating individual tree nodes, the heap represents a complete binary tree through array indices.

For a node at index `i`, its relatives are calculated as:

```text
Parent Index      = (i - 1) / 2
Left Child Index  = 2 * i + 1
Right Child Index = 2 * i + 2
```

This representation eliminates the need for explicit child pointers and allows direct access to parent and child positions.

The heap maintains the Max Heap property, where each parent has a value greater than or equal to its children.

### 2. <ins>Heap Insertion and Removal</ins>

The heap maintains its ordering through two fundamental operations.

**Insertion — Upward Reordering**

When inserting a new element:

1. The element is placed at the end of the array.
2. Its value is compared with its parent's value.
3. If the new element is greater, the two elements are swapped.
4. This process repeats until the heap property is restored.

This process is commonly called *sift-up* or *heapify-up*.

**Removal — Downward Reordering**

When removing an element:

1. The root element, containing the maximum value, is saved.
2. The last element replaces the root.
3. The replacement element is compared with its children.
4. The element is moved downward as necessary to restore heap ordering.

This process is commonly called *sift-down* or *heapify-down*.

Both operations are designed to maintain the heap's ordering without sorting the entire collection.

### 3. <ins>Priority Queue Implementation</ins>

The `PQueue<T>` class builds a priority queue on top of the Max Heap.

```cpp
Heap<info<T>> _heap;
```

Each inserted element is wrapped in an `info<T>` structure containing:

```cpp
T item;
int priority;
int timeStamp;
```

The queue assigns an incrementing timestamp to each inserted element.

The custom comparison operators prioritize elements according to two rules:

1. **Higher Priority First:** Elements with larger priority values are processed before elements with smaller priority values.
2. **Earlier Insertion First:** When priorities are equal, elements with smaller timestamps are processed first.

This creates a stable priority ordering that preserves insertion order among equal-priority elements.

---

## Priority Queue Example

Consider inserting the following elements:

| Element | Priority | Insertion Order |
|---------|----------|-----------------|
| Alice | 3 | 0 |
| Bob | 5 | 1 |
| Charlie | 3 | 2 |
| David | 5 | 3 |
| Eve | 1 | 4 |

The priority queue processes them in the following order:

```text
1. Bob      (Priority: 5, Timestamp: 1)
2. David    (Priority: 5, Timestamp: 3)
3. Alice    (Priority: 3, Timestamp: 0)
4. Charlie  (Priority: 3, Timestamp: 2)
5. Eve      (Priority: 1, Timestamp: 4)
```

Although Bob and David have the same priority, Bob is processed first because he was inserted earlier.

The same principle applies to Alice and Charlie.

---

## Design Rationale

An array-based Max Heap provides an efficient foundation for priority-based processing because it maintains the highest-priority element at the root without requiring the entire collection to remain sorted.

Using array indices instead of dynamically allocated tree nodes simplifies parent-child navigation and keeps heap storage contiguous. The Priority Queue builds on this structure by wrapping each element with priority metadata and an insertion timestamp.

This separation allows the heap to handle element ordering while the Priority Queue provides priority-based scheduling with deterministic FIFO tie-breaking.

---

## Supported Operations

| Component | Operation | Function | Description |
|-----------|-----------|----------|-------------|
| Heap | Insert | `insert()` | Inserts an element and restores heap ordering |
| Heap | Remove | `remove()` | Removes and returns the maximum element |
| Heap | Top | `top()` | Returns the root element |
| Heap | Size | `size()` | Returns the number of stored elements |
| Heap | Check Empty | `is_empty()` | Determines whether the heap is empty |
| Heap | Verify | `verify()` | Checks the heap ordering property |
| Heap | Copy Array | `heap_array()` | Returns a dynamically allocated copy of the underlying array |
| Priority Queue | Push | `push()` | Inserts an element with a specified priority |
| Priority Queue | Pop | `pop()` | Removes the highest-priority element |
| Priority Queue | Top | `top()` | Returns the highest-priority entry with metadata |
| Priority Queue | Size | `size()` | Returns the number of queued elements |
| Priority Queue | Check Empty | `is_empty()` | Determines whether the queue is empty |

---

## Core Components

| File | Responsibility |
|------|----------------|
| `heap.h` | Implements the array-based Max Heap, insertion, removal, and heap verification |
| `pqueue.h` | Implements the Priority Queue using the underlying Max Heap |
| `info.h` | Stores item values, priorities, and insertion timestamps with custom comparison operators |
| `basic_test.cpp` | Exercises heap and priority queue behavior using GoogleTest |
| `testB.cpp` | Contains additional heap and priority queue test scenarios and debugging utilities |

---

## Time Complexity

For a binary heap containing `n` elements:

| Operation | Time Complexity |
|-----------|-----------------|
| Insert | O(log n) |
| Remove Maximum | O(log n) |
| Access Maximum | O(1) |
| Check Empty | O(1) |
| Get Size | O(1) |
| Verify Heap | O(n) |
| Copy Underlying Array | O(n) |

Insertion and removal operate along the height of the heap, which is logarithmic in the number of elements.

The implementation uses a fixed capacity of 1,000 elements.

---

## Testing

The project includes C++ test programs using **GoogleTest** to exercise heap operations and priority-based processing.

Testing scenarios include:

- Inserting multiple elements into a Max Heap.
- Removing elements in descending priority order.
- Checking heap ordering after insertion and removal.
- Processing elements with different priority levels.
- Observing FIFO tie-breaking among equal-priority elements.
- Printing heap structures and underlying array contents.
- Testing heap behavior with randomized input values.

The tests combine GoogleTest test cases with console-based output and structural inspection.

---

## Project Information

**Language:** C++  
**Data Structures:** Max Heap, Priority Queue  
**Heap Representation:** Fixed-capacity array  
**Priority Ordering:** Highest priority first, FIFO for equal priorities  
**Testing:** GoogleTest  
**Core Concepts:** Heap algorithms, binary trees, templates, custom comparison operators, and priority-based scheduling

**Developer:** Queency Tan


