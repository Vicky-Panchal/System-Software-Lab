import React from "react";
import { BsHandbag } from 'react-icons/bs';
import { RiAccountCircleLine } from 'react-icons/ri'; // Import the account icon you prefer
import { useSelector } from 'react-redux';
import { useNavigate } from 'react-router-dom';
import { TbBuildingStore } from 'react-icons/tb';

import "../styles/Navbar.css";

function Navbar() {
    const products = useSelector(state => state.navbarReducer.value);

    function numberOfProducts() {
        let number = 0;
        for (let i = 0; i < products.length; i++) {
            number += products[i].quantity;
        }
        return number;
    }

    const navigate = useNavigate();

    function handleClickIcon() {
        navigate("/");
        window.scroll({ top: 0, behavior: 'smooth' });
    }

    function handleClickHandBag() {
        navigate("/shoppingCart");
        window.scroll({ top: 0, behavior: 'smooth' });
    }

    function handleAccountClick() {
        navigate("/account"); // Replace "/account" with your account page route
        window.scroll({ top: 0, behavior: 'smooth' });
    }

    return (
        <div id="navbar-container">
            <div id="icon">
                <TbBuildingStore id="icon-in-div" onClick={handleClickIcon} />
            </div>
            <RiAccountCircleLine id="account-icon" onClick={handleAccountClick} />
            <BsHandbag id="hand-bag" onClick={handleClickHandBag} />
            <div id="number-of-products">{numberOfProducts()}</div>
        </div>
    );
}

export default Navbar;
