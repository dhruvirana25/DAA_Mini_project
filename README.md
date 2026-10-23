# Smart Contact Search System

## 1. Project Overview
The Smart Contact Search System is a simple contact management application developed as part of the Design and Analysis of Algorithms (DAA) project. It allows users to search for contacts by name, add new contacts, view contacts in alphabetical order, and delete contacts through a user-friendly interface.

The project demonstrates the practical application of string matching and sorting algorithms.

## 2. Objectives
- To implement contact searching using the Naive String Matching algorithm.
- To arrange contacts alphabetically using sorting.
- To provide a simple and interactive user interface.
- To demonstrate the practical use of DAA concepts in a real-world application.

## 3. Technologies Used
- **HTML:** Structure of the web interface.
- **CSS:** Styling and layout.
- **JavaScript:** UI interactions and browser-side contact operations.
- **C++:** Core DAA implementation of the searching algorithm and sorting logic.

## 4. Features
- Search contacts by name.
- Add new contacts with name and phone number.
- Display contacts alphabetically.
- Delete contacts.
- Store browser-side contact data using Local Storage.
- Simple dark navy and electric blue user interface.

## 5. Algorithms Used

### Naive String Matching
The Naive String Matching algorithm checks a search pattern against a text by comparing characters at each possible position. It is used to demonstrate contact-name searching.

**Time Complexity:**
- Best case: O(n), depending on the implementation.
- Worst case: O(n × m).

Here, n is the length of the text and m is the length of the search pattern.

### Sorting
Sorting arranges contacts in alphabetical order by name. The specific sorting algorithm and its complexity should match the C++ implementation used in the project.

## 6. Project Structure
- `index.html` — Main webpage structure.
- `style.css` — Styling and visual design.
- `script.js` — Browser-side functionality.
- `README.txt` — Project documentation.
- C++ source file — DAA algorithm implementation.

## 7. How to Run the Project
1. Extract the project folder.
2. Open the folder in Visual Studio Code.
3. Ensure that `index.html`, `style.css`, and `script.js` are in the correct locations.
4. Open `index.html` in a web browser, or use the Live Server extension in VS Code.
5. Use the interface to add, search, view, and delete contacts.

No additional framework or package installation is required to run the basic web interface.

## 8. Important Implementation Note
The HTML, CSS, and JavaScript files provide the interactive web interface. The C++ source file demonstrates the DAA algorithms separately unless an explicit connection between the web interface and the C++ program is implemented.

## 9. Conclusion
The Smart Contact Search System demonstrates how searching and sorting algorithms can be applied to contact management. The project combines algorithmic concepts with a simple web interface to make contact operations easier to understand and use.

It also provides a foundation for future improvements, such as more efficient searching, contact editing, and integration of the C++ implementation with the user interface.
