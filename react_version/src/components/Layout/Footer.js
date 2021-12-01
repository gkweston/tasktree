import React from 'react';
import { connect } from 'react-redux';
import BottomNavigation from '@material-ui/core/BottomNavigation';
import BottomNavigationAction from '@material-ui/core/BottomNavigationAction';
import AddIcon from '@material-ui/icons/AddCircleRounded';
import PlaylistAdd from '@material-ui/icons/PlaylistAdd';
import {
  createNode,
  clearNodes
} from '../../store/hierarchy/nodes';
import { clearCompleted } from '../../store/tasks/actions';

const Footer = ({ createNode, clearNodes, clearCompleted }) => {
  const addClick = () => {
    createNode({
      data: {
        text: ''
      }
    });
  };

  const newClick = () => {
    clearNodes();
    localStorage.setItem('score', '0');
  };

  return (
    <BottomNavigation style={{ backgroundColor: 'white' }}>
      <BottomNavigationAction
        label='Add Task'
        showLabel
        onClick={addClick}
        icon={<AddIcon style={{ color:'#173679' }} />}
      />
      <BottomNavigationAction
        label='New List'
        showLabel
        onClick={newClick}
        icon={<PlaylistAdd style={{ color:'#173679' }} />}
      />
    </BottomNavigation>
  );
};

const mapDispatchToProps = dispatch => {
  return {
    createNode: payload => dispatch(createNode('tasks', payload)),
    clearNodes: () => dispatch(clearNodes('tasks')),
    clearCompleted: () => dispatch(clearCompleted())
  };
};

export default connect(
  null,
  mapDispatchToProps
)(Footer);
