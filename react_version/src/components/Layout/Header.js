import React from 'react'
import AppBar from '@material-ui/core/AppBar'
import Toolbar from '@material-ui/core/ToolBar'
import Box from '@material-ui/core/Box'


const Header = () => {
  return (
    <div style={{ flex: '0 0 auto', zIndex: 1}}>
      <AppBar style={{ background: 'white' }}>
        <Toolbar>
          <Box
            component="img"
            sx={{height: 64,}} 
            alt="Logo"
            src="StarLog.png"
          />
        </Toolbar>
      </AppBar>
    </div>
  );
};

export default Header;
