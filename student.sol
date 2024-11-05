// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StudentData {
    // Define a struct to store student information
    struct Student {
        uint256 id;
        string name;
        uint8 age;
        string grade;
    }

    // Mapping to store each student by their ID
    mapping(uint256 => Student) private students;

    // Array to store student IDs for iteration
    uint256[] private studentIds;

    // Constructor to initialize some students (optional)
    constructor() {
        // Example initialization
        addStudent(1, "AA", 20, "A");
        addStudent(2, "BB", 22, "B");
        addStudent(3, "CC", 21, "A");
    }

    // Function to add a new student
    function addStudent(uint256 _id, string memory _name, uint8 _age, string memory _grade) public {
        require(students[_id].id == 0, "Student with this ID already exists.");

        students[_id] = Student(_id, _name, _age, _grade);
        studentIds.push(_id);
    }

    // Function to retrieve student details by ID
    function getStudent(uint256 _id) public view returns (uint256, string memory, uint8, string memory) {
        require(students[_id].id != 0, "Student not found.");
        
        Student memory student = students[_id];
        return (student.id, student.name, student.age, student.grade);
    }

    // Function to retrieve all student IDs
    function getAllStudentIds() public view returns (uint256[] memory) {
        return studentIds;
    }

    // Fallback function to prevent accidental ether transfers
    fallback() external payable {
        revert("Contract does not accept Ether.");
    }

    // Receive function to prevent accidental ether transfers
    receive() external payable {
        revert("Contract does not accept Ether.");
    }
}
