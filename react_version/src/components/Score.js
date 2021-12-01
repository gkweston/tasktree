import React from 'react';
import ExplosionL0 from 'react-explode/Guyam'
import ExplosionL1 from 'react-explode/Boracay'
import ExplosionL2 from 'react-explode/Corregidor'
import ExplosionL3 from 'react-explode/Siquijor'
import ExplosionL4 from 'react-explode/Ticao'
import ExplosionL5 from 'react-explode/Babuyan'

const divStyle = {
  backgroundColor: "white",
  borderRadius:20,
  borderWidth:2,
  borderColor:'gold',
  margin:10
}
  
const h3Style = {
  color:"black",
  margin: 10,
  zIndex: -1,
  padding:10
}

const explodeStyle = {
  position: 'absolute',
  marginTop: '-8em',
  marginLeft: '-5em',
  zIndex: 2
}

//event listener for local storage
function Score() {
  const score = parseInt(localStorage.getItem('score'));
  var isZero = false;
  if (score < 15) {
    isZero = true;
  }
  var isL1 = false;
  if (score !== 0 && score % 15 === 0) {
    isL1 = true;
  }
  var isL2 = false;
  if (score !== 0 && score % 30 === 0) {
    isL2 = true;
  }
  var isL3 = false;
  if (score !== 0 && score % 60 === 0) {
    isL3 = true;
  }
  var isL4 = false; //last
  if (score !== 0 && score % 90 === 0) {
    isL4 = true;
  }
  var isL5 = false;
  if (score !== 0 && score % 120 === 0) {
    isL5 = true;
  }

  return (
    <>
      
      <div style={divStyle}>
        {/* Different explosion renders */}
        {isZero && <div style={explodeStyle}>
          <ExplosionL0 size="300" color="DarkSlateBlue" />
        </div>}
        {isL1 && <div style={explodeStyle}>
          <ExplosionL1 size="300" color="#E8E163" />
        </div>}
        {isL2 && <div style={explodeStyle}>
          <ExplosionL2 size="300" color="GoldenRod" />
        </div>}
        {isL3 && <div style={explodeStyle}>
          <ExplosionL3 size="300" color="#DB901C" />
        </div>}
        {isL4 && <div style={explodeStyle}>
          <ExplosionL4 size="300" color="7FC5DC" />
        </div>}
        {isL5 && <div style={explodeStyle}>
          <ExplosionL5 size="300" color="RoyalBlue" />
        </div>}

        {/* Display score */}
        <h3 style={h3Style}>Score: {score}</h3>
      </div>
    </>
  );
}

export default Score;
