# 🌀 Ge-Git – Build Your Own Git in C

**Ge-Git** is a lightweight Git implementation in C that mimics Git's internal object storage system, including support for blob, tree, and commit objects.

---

## 🚀 Features

- ✅ `init` – Initialize a `.gegit` directory
- ✅ `hash-object` – Create blob objects from file content
- ✅ `write-tree` – Generate tree objects from directory structure
- ✅ `commit` – Create commit objects referencing tree objects
- ✅ Stores all Git-like objects in `.gegit/objects/<sha1>`

---

## 🧠 Internals

This project closely follows how Git internally handles content:

| Object Type | Format                                              | Stored In                                      |
|-------------|------------------------------------------------------|------------------------------------------------|
| **Blob**    | `blob <size>\0<content>`                             | `.gegit/objects/<first2>/<rest38>`             |
| **Tree**    | `tree <size>\0<entries>` per file                    | `.gegit/objects/<sha1>`                        |
| **Commit**  | `commit <size>\0tree <sha>\nauthor...\n<message>`    | `.gegit/objects/<sha1>`                        |

---

## 📦 File Structure
```
Ge-Git/
├── .gegit/                  # Custom .git-like directory for storing objects
│   └── objects/             # Contains all git objects (blobs, trees, commits)
│       └── <hash-prefix>/
│           └── <object-file>
├── .vscode/                 # VS Code settings (optional)
├── include/                # Header files
│   ├── commit.h
│   ├── hash_object.h
│   ├── init.h
│   ├── tree.h
│   └── utils.h
├── src/                    # Source files
│   ├── commit.c
│   ├── hash_object.c
│   ├── init.c
│   ├── tree.c
│   └── utils.c
├── hello.txt               # Sample file to hash
├── main.c                  # CLI entry point
├── gegit                   # Compiled binary
└── Makefile                # Build script


```

## 🧪 Example Usage

### 🟢 Initialize repository

```bash
./gegit init

📦 Hash a file as a blob

./gegit hash-object hello.txt

🌲 Write tree from current directory

./gegit write-tree

📝 Commit the tree

./gegit commit "initial commit"
```

## 🪪 License

MIT License © Meerthika
