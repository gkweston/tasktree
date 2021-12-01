import React from 'react';
import { connect } from 'react-redux';
import { SortableElement, sortableHandle } from 'react-sortable-hoc';
import { uniqueId } from 'lodash';
import { ListItem } from '@material-ui/core';
import { DragHandle } from '@material-ui/icons';
import TextField from '@material-ui/core/TextField';
import Checkbox from '@material-ui/core/Checkbox';
import {
  indentNode,
  unindentNode,
  updateNode,
  deleteNode,
  createNode
} from '../../store/hierarchy/nodes';

const DraggableHandle = sortableHandle(() => (
  <DragHandle style={{ cursor: 'grab' }} />
));

const Task = ({
  id,
  parent,
  data,
  completed,
  descendants,
  ancestors,
  depth,
  createNode,
  deleteNode,
  indentNode,
  unindentNode,
  updateNode,
  dragging,
  left,
  right
}) => {
  const onKeyDownHandler = event => {
    if (event.key === 'Tab' || (event.key === 'Tab' && event.shiftKey)) {
      event.preventDefault();
    }

    if (event.key === 'Tab' && event.shiftKey) {
      unindentNode({
        id
      });
    } else if (event.key === 'Tab' && !event.shiftKey) {
      indentNode({
        id
      });
    }

    if (event.key === 'Backspace' && data.text.length === 0) {
      deleteNode({
        id
      });
    }

    if (event.key === 'Enter') {
      const newId = uniqueId();
      createNode({
        id: newId,
        parent: parent.id,
        data: {
          text: ''
        }
      });

      setTimeout(() => {
        document.querySelector(`#text-${newId}`).focus();
      }, 50);
    }

    if (event.key === 'ArrowDown' && right) {
      document.querySelector(`#text-${right.id}`).focus();
    }

    if (event.key === 'ArrowUp' && left) {
      document.querySelector(`#text-${left.id}`).focus();
    }
  };

  const textOnChange = event => {
    updateNode({
      id,
      data: {
        ...data,
        text: event.target.value
      }
    });
  };

  // eslint-disable-next-line
  const checkOnChange = event => {
    const toUpdate = [...descendants, id];
    toUpdate.forEach(id => {
      updateNode({
        id,
        completed: event.target.checked
      });
    });

    if (parent.id !== 'root') {
      ancestors.forEach(id => {
        updateNode({
          id,
          completed: false
        });
      });
    }
  };

  const opacity = dragging ? 0.7 : 1;

  return (
    <ListItem style={{ backgroundColor: 'white' }}>
      <DraggableHandle style={{ color:'#450B8F' }} />
      <span
        style={{
          width: '100%',
          marginLeft: depth * 15,
          opacity,
          display: 'flex',
          flexDirection: 'row'
        }}
      >
        <TextField
          color = 'primary'
          id={`text-${id}`}
          fullWidth
          margin='normal'
          onKeyDown={onKeyDownHandler}
          onChange={textOnChange}
          value={data.text}
        />
        <Checkbox
          checked={completed}
          value={completed}
          color='primary'
          // Update score in local mem, don't ask me why this doesn't work as a modular
          // function, but it doesn't work as a modular function
          onChange = { () => {
            const score = localStorage.getItem('score');
            localStorage.setItem('score', parseInt(score) + 15);
            deleteNode({ id });
          }}
        />
      </span>
    </ListItem>
  );
};

const mapDispatchToProps = dispatch => {
  return {
    indentNode: payload => dispatch(indentNode('tasks', payload)),
    unindentNode: payload => dispatch(unindentNode('tasks', payload)),
    updateNode: payload => dispatch(updateNode('tasks', payload)),
    deleteNode: payload => dispatch(deleteNode('tasks', payload)),
    createNode: payload => dispatch(createNode('tasks', payload))
  };
};

export default connect(
  null,
  mapDispatchToProps
)(SortableElement(Task));
