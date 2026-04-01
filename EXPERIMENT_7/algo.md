# Cheapest Flights Within K Stops - Algorithm

## Step 1: Create Graph
- Make an adjacency list
- For each flight `[u, v, price]`
  - Store `(v, price)` in `u`

---

## Step 2: Initialize
- Create a cost array of size `n`
- Set all values = `INT_MAX`
- Set `cost[src] = 0`

- Create a queue  
  - Store: `(node, cost, stops)`
  - Push `(src, 0, 0)`

---

## Step 3: BFS Traversal

Repeat until queue is empty:

- Take front element:
  - `node, currCost, stops`

- If `stops > k`
  - Skip this path

- For all neighbors of `node`:
  - Let `next` be neighbor
  - Let `price` be cost to go there

- If `currCost + price < cost[next]`
  - Then:
    - Update `cost[next]`
    - Push `(next, newCost, stops + 1)` into queue

---

## Step 4: Return Answer

- If `cost[dst] == INT_MAX`
  - Return `-1`
- Else
  - Return `cost[dst]`