import React from 'react';
import './App.css';
import TaskListContainer from './components/Tasks/TaskListContainer';
import Header from './components/Layout/Header';
import Footer from './components/Layout/Footer';

function App() {
  // init score to 0
  localStorage.setItem("score", "0")
  return (
    <div className='App'>
      <Header />
      <TaskListContainer />
      <Footer />
    </div>
  );
}

export default App;
