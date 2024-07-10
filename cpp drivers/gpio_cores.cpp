// gpo core class implementation

#include "gpio_cores.h"

//**********************************************************************/
//  GpoCore                                                             /
//**********************************************************************/
GpoCore::GpoCore (uint32_t core_base_addr){

    base_addr = core_base_addr;
    wr_data = 0;
};

GpoCore::~GpoCore() {};

// writting a whole word
void GpoCore::write(uint32_t data){

    wr_data = data;
    io_write(base_addr, DATA_REG, wr_data);
  //io_write(base_addr, offset, data)   ( *(volatile uint32_t *) ( (base_addr) + 4 * (offset) )  = (data) )
};


// writting to a singlr bit
void GpoCore::write (int bit_value, int bit_pos) {

    bit_write(wr_data, bit_pos, bit_value);
    io_write(base_addr, DATA_REG, wr_data);
  //io_write(base_addr, offset, data)   ( *(volatile uint32_t *) ( (base_addr) + 4 * (offset) )  = (data) ) 
};


//**********************************************************************/
//                                                                      /
//**********************************************************************/







//**********************************************************************/
//  GpiCore                                                             /
//**********************************************************************/
GpiCore::GpiCore (uint32_t core_base_addr){

    base_addr = core_base_addr;

};

GpiCore::~GpiCore(){};

void GpiCore::read(){
          //io_read(base_addr, offset)          ( *(volatile uint32_t *) ( (base_addr) + 4 * (offset) ) )
    return (io_read(base_addr, DATA_REG));

};

int GpiCore::read(int bit_pos){

    uint32_t rd_data = io_read(base_addr, DATA_REG);
    return ((int) bit_read(rd_data, bit_pos));
                //io_read(base_addr, offset)          ( *(volatile uint32_t *) ( (base_addr) + 4 * (offset) ) )
};


//**********************************************************************/
//                                                                      /
//**********************************************************************/
