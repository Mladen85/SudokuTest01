# Sudoku test project


This project is for learning and testing purpose.
Any idea, suggestion, improvement, comment are welcome.

General idea is for program to auto generate random sudoku,
remove defined number of fields (based on difficulty level),
find all possible solutions for new sudoku and write them
all to list.

During solving sudoku it is possible to check if user solution
is correct at any time.

# Compile and Run
## Compile and Run project
Execute commands from repository root folder:
```
cd user_app
make run
```
## Compile project
Execute commands from repository root folder:
```
cd user_app
make
```
or
```
cd user_app
make all
```
`all` is default rule<br>
(because of line `all : $(TARGET)`)
## Run project
Execute commands from repository root folder:
```
cd user_app
./sudoku_app.exe
```
or
```
cd user_app
make run
```

# `development`
## Issues
- [ ] [Loading data from file to list](https://github.com/Mladen85/SudokuTest01/issues/9)
- 

## TODOs
- [ ] Generate new sudoku.
- [ ] Prepare sudoku for solving.
- [ ] Find all possible solutions.
- [ ] Create main menu.


# Branching:
## `master` branch
Will be used for release version.

## `development` branch
Will be used during development.<br>
Release versions will be merged to `master` branch.

## `feature-XXX` branch
Will be used for feature adding.<br>
Feature complete will be merged to `development` branch.<br>
`feature-XXX` branch will be deleted after merge.

## `plan-upd-XXX` branch
Will be used to update planning documents.<br>
will be merged to `master` branch.<br>
`plan-upd-XXX` branch will be deleted after merge.

## `path-XX.XX.XX` branch
Will be used in case project is split to different development paths.


# TODO list
- [ ] Create SW architecture<br>
- [ ] Add source files (Initialize project)<br>
- [ ] Development phase<br>


# How to fix remote: error: GH007: Your push would publish a private email address
1. Open Terminal.

2. Change the current working directory to the local repository where you want to configure the email address that you associate with your Git commits.

3. Find your GitHub noreply address in your GitHub's Personal Settings → Emails. It's mentioned in the description of the Keep my email address private checkbox. Usually, it starts with a unique identifier, plus your username.

4. Set an email address in Git. Use your GitHub-provided no-reply email address.
- Setting your email address for every repository on your computer
    `git config --global user.email "{ID}+{username}@users.noreply.github.com"`

- Setting your email address for a single repository
    `git config user.email "{ID}+{username}@users.noreply.github.com"`

5. Reset the author information on your last commit:
    `git commit --amend --reset-author`
- If you have multiple commits with your private e-mail address, see this answer.

6. Now you can push the commit with the noreply e-mail address, and future commits will have the noreply e-mail address as well.
    `git push -u origin master`
