# Compilation and execution istructions
For compilation and execution use the following commands:

## On Linux-like operating systems
C (GNU Toolchain) is already included in all Unix like systems.

Using a terminal shell, navigate to the directory where you have saved the files of this repository:

```sh
cd ~/Path/To/Repo/02_Structure_of_operating_systems/Part_1_Creating_installing_removing_kernel_modules/
```
# Definitions of message exchange communcation system functions

## Direct communication

Direct communication between processes by means of message exchange has the following properties:

* Messages are exchanged directly between processes.

* Only one communication channel is associated to exactly two processes.

* Reciprocal identity knowledge needed.

* Symmetrical or asymmetrical addressing.

* Prior hard coding of instructions.

### Direct symmetrical communication

`send(P, message)`: send a message to process P.

`receive(Q, message)`: receive a message from process Q.

### Direct asymmetrical communication

`send(P, message)`: send a message to process P.

`receive(id, message)`: receive a message from un undefined process. By the `id` variable is obtained the name of the process with whon the communication was made.

## Indirect communication

Indirect communication between processes by means of message exchange has the following properties:

* Messages are exchanged between processes and mailboxes/ports.

* Many communication channel can be associated to two or more processes.

* Reciprocal share of mailbox needed.

* A mailbox might be part of the system or of the processes.

* Synchronized/Unsynchronized send/receive messages.

* No prior hard coding of instructions.

`send(A, message)`: send a message to mailbox A.

`receive(A, message)`: receive a message from mailbox A.
