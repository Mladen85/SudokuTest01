# Sudoku test project


This project is for learning and testing purpose.
Any idea, suggestion, improvement, comment are welcome.

General idea is for program to auto generate random sudoku,
remove defined number of fields (based on difficulty level),
find all possible solutions for new sudoku and write them
all to list.

During solving sudoku it is possible to check if user solution
is correct at any time.

# `path-00.01.00`
In this project branch is saved old project structure.

## Description
Because of fixing bugs New project structure is considered (simple one).<br>
After working version of project reconsider setting project structure like in this branch.

Note that initial source code files are from `master` init state.

Tree like:
-dev_app/
 |-inc/
 |-obj/
 |-src/
 |-Makefile
-lib/
 |-inc/
 |-obj/
 |-src/
 |-lib<library>.a
 |-Makefile
-user_app/
 |-main.c
 |-test.c
 |-Makefile

## Issue
[Issue](https://github.com/Mladen85/SudokuTest01/issues/7) for this path is created.


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
- [ ] Create SW architecture
- [ ] Add source files (Initialize project)
- [ ] Development phase
- [ ] Add explanation for Tags


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
