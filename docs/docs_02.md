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
```bash
$ dialga --version
0.0.1
```
## Initializing a Repository

To start version controlling a project, navigate to your project directory and initialize a Dialga repository:

```bash
$ dialga init
```

This command creates a `.dlgx` directory where Dialga stores its metadata.

## Tracking Changes (to be added) 

Dialga tracks changes to your files similarly to Git. You can add files to the staging area using:

```bash
$ dialga add <file>
```

Replace `<file>` with the name of the file you want to add. You can also use `.` to add all files in the current directory.

## Committing Changes 

Once you have added files to the staging area, commit the changes to the repository:

```bash
$ dialga commit <file_name>
```

## Checking Status (to be added) 

To see the status of your repository, including tracked/untracked files and modifications:

```bash
$ dialga status
```

## Viewing Commit History (to be added) 

You can view the commit history to see all previous commits and their messages:

```bash
$ dialga log
```



