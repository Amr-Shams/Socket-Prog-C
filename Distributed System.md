

---

# Distributed Systems

## Why Distributed Systems?

[Watch the video](https://www.youtube.com/watch?v=s_p3I5CMGJw)

### The Wrong Reasons:
- **It's Fun**: Developing distributed systems should be driven by practical needs, not just for the sake of it.
- **My Boss Tells Me**: Following trends without understanding the underlying requirements.
- **Future Scalability**: Distributing systems without the necessary expertise can lead to inefficiencies.

### The Right Reasons:
- **Scalability**: Balancing load across multiple machines.
- **Reducing Latency**: Serving user requests as fast as possible by placing servers closer to users.
- **Availability & Fault Tolerance**: Ensuring systems remain operational even under failures.
- **Data Residency**: Complying with legal requirements for data location.

## Key Concepts

### Node:
- Contains compute (CPU) and state (memory, disk).
- Can be a standalone machine or a running process in a distributed system.

### Compute:
- The CPU, responsible for performing actual work.

### State:
- Holds data in memory, on disk, or in a database.

### Distributed Systems:
- Splitting compute, state, or both into multiple machines.
- Communication occurs asynchronously through unreliable channels.

## Stateless vs. Stateful Distributed Systems

### Stateless Distributed System:
- State is offloaded, not held by individual machines.
- State is persisted elsewhere, and machines access it.
- E.g., web applications accessing a common database cluster.

### Stateful Distributed System:
- Each node holds its state.
- Replicas: Nodes with identical states.
- Strong Consistency: States are always the same.
- Eventual Consistency: States will eventually be the same.
- Sharding/Partitioning: State is divided across nodes.

## Fault Tolerance

### Node Failures:
- Fail-Stop (Hard Failure): Node is either running or stopped.
- Gray Failure (Byzantine Failure): Node is running but behaves incorrectly.

### Network Failures:
- Fail-Stop (Hard Failure).
- Gray Failure (Byzantine Failure).

### Network Partitioning Problem:
- Subset of nodes isolated, believing they are the only ones alive.

## CAP Theorem

C (Consistency), A (Availability), P (Partition Tolerance)

## Trade-offs in Fault Tolerance
- Not all failures need to be tolerated; it depends on the use case.
- Engineering involves making trade-offs.
- Recovery from failure is often more important than fault tolerance.

## Two Generals Problem

- Coordination problem in which two armies need to attack simultaneously.
- Infinite message exchange required for absolute assurance.
- Known as the consensus problem.

## Byzantine Generals Problem

- Similar to the Two Generals Problem, but with guaranteed message delivery.
- Messages may be corrupted or messengers disloyal.
- Addresses gray failures.

## Consensus Problem

- All nodes must agree on one state in unreliable communication channels.
- Algorithms like Paxos and Raft specialize in solving the consensus problem.

---

These notes have been structured to provide a clear overview of distributed systems, the reasons behind their adoption, key concepts, fault tolerance, and challenges related to consensus. Each section is organized logically, making it easier to understand the subject matter.