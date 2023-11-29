import React, { useState } from "react";
import '../styles/Account.css'
function Account() {
  // Mock user data (you might fetch this from an API)
  const [user, setUser] = useState({
    name: "Vicky Panchal",
    email: "vicky@gmail.com",
    address: "IIIT Bangalore",
  });

  const [editMode, setEditMode] = useState(false);

  const handleInputChange = (e) => {
    setUser({
      ...user,
      [e.target.name]: e.target.value,
    });
  };

  const handleEditProfile = () => {
    setEditMode(true);
  };

  const handleSaveProfile = () => {
    setEditMode(false);
    // Here you might send updated user data to the server
    console.log("Updated User Data:", user);
  };

  const handleLogout = () => {
    // Your logout logic here (e.g., clearing tokens, etc.)
    console.log("Logged out");
  };

  return (
    <div className="account-page">
      <h1>Account Details</h1>
      <div className="user-details">
        <label>
          Name:
          {editMode ? (
            <input
              type="text"
              name="name"
              value={user.name}
              onChange={handleInputChange}
            />
          ) : (
            <span>{user.name}</span>
          )}
        </label>
        <label>
          Email:
          <span>{user.email}</span>
        </label>
        <label>
          Address:
          {editMode ? (
            <input
              type="text"
              name="address"
              value={user.address}
              onChange={handleInputChange}
            />
          ) : (
            <span>{user.address}</span>
          )}
        </label>
      </div>
      <div className="actions">
        {editMode ? (
          <button onClick={handleSaveProfile}>Save Profile</button>
        ) : (
          <button onClick={handleEditProfile}>Edit Profile</button>
        )}
        <button onClick={handleLogout}>Log Out</button>
      </div>
    </div>
  );
}

export default Account;
