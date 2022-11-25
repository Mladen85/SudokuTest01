# Sudoku test project


This project is for learning and testing purpose.
Any idea, suggestion, improvement, comment are welcome.

General idea is for program to auto generate random sudoku,
remove defined number of fields (based on difficulty level),
find all possible solutions for new sudoku and write them
all to list.

During solving sudoku it is possible to check if user solution
is correct at any time.

## How to fix remote: error: GH007: Your push would publish a private email address
1. Open Terminal.

2. Change the current working directory to the local repository where you want to configure the email address that you associate with your Git commits.

3. Find your GitHub noreply address in your GitHub's Personal Settings → Emails. It's mentioned in the description of the Keep my email address private checkbox. Usually, it starts with a unique identifier, plus your username.

4. Set an email address in Git. Use your GitHub-provided no-reply email address.
- Setting your email address for every repository on your computer
- `git config --global user.email "{ID}+{username}@users.noreply.github.com"`

- Setting your email address for a single repository
- `git config user.email "{ID}+{username}@users.noreply.github.com"`

5. Reset the author information on your last commit:
- `git commit --amend --reset-author`
- If you have multiple commits with your private e-mail address, see this answer.

6. Now you can push the commit with the noreply e-mail address, and future commits will have the noreply e-mail address as well.
- `git push -u origin master`
