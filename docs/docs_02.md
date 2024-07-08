---
outline: deep
---

# How to use 

Dialga provides a robust version control system that helps you manage and track changes in your projects effectively, using familiar Git-like commands and workflows.

## Add to `path`
```bash
$ export PATH="<path to dialga binary>:$PATH"
```
refresh your shell profile afterwards, then check if Dialga is ready to use

> note: we are assuming dialga is added to `$PATH`. If not, please add a `./` prefix everytime the binary is called.

```bash
$ dialga --version
0.1.0
```
## Initializing a Repository

To start version controlling a project, navigate to your project directory and initialize a Dialga repository:

```bash
$ dialga init
```

This command creates a `.dlgx` directory where Dialga stores its metadata.

## Committing Changes 

Dialga doesn't use a staging area, and infact tracks commits through the `.commit` file. 

```bash
$ dialga commit <file_name> <commit_message>
```

## Viewing Commit History (to be added) 

You can view the commit history to see all previous commits and their messages:

```bash
$ dialga history
```

## Restoring changes

Dialga can only restore changes upto the base directory for now. To restore a change, grab the hash of the commit from history.

```bash
$ dialga restore <commit_hash>
```

