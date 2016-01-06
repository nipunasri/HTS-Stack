#ifndef _HTS_CONSTS_HPP_
#define _HTS_CONSTS_HPP_


#define  HTS_OK                            (1)
#define  HTS_NOT_OK                        (-1)

#define  THREAD_REQUEST_BUFFER_SIZE        (512)

#define  REQ_QUEUE_SIZE                    (1024)
#define  REQ_QUEUE_SIZE_MASK               (0x03FF)

#define  OCL_REQ_QUEUE_SIZE                (4096)
#define  OCL_NODE_POOL_SIZE                (1048576)
#define  OCL_HASH_TABLE_SIZE               (1024)
#define  OCL_HASH_TABLE_MASK               (0x3FF)
#define  OCL_WG_SIZE                       (256)
#define  EMPTY_KEY                         (0) 

#define  SET_FLAG(f,b)                     ((f) | (b))
#define  RESET_FLAG(f,b)                   ((f) & ~(b))
#define  GET_FLAG(f,b)                     ((f) & (b))
#define  GET_PTR(f)                        ((f) >> 3) // Modified
#define  SET_PTR(f)                        ((f) << 3) // Modified
//#define  GET_PTR(f)                        ((f)>> 1) 
//#define  SET_PTR(f)                        ((f)<< 1) 

// checks whether given bit position in given value is set or not
#define IS_SET(f,p)						   ((f>>p) & 1)

// for get-bits
#define GET_BITS(f)						   ((f) & (0x07))
// for Reset-bit
#define	 GET_FBIT(f)					   ((f) & (0x04))	 
#define  SET_FBIT(f)                       ((f) | (0x04))	
#define  RESET_FBIT(f)                     ((f) & (~0x04))	 
// for Retain-bit
#define  GET_RBIT(f)                       ((f) & (0x02)) 
#define  SET_RBIT(f)                       ((f) | (0x02)) 
#define  RESET_RBIT(f)                     ((f) & (~0x02))
// for Deletion-bit
#define  GET_DBIT(f)                       ((f) & (0x01)) 
#define  SET_DBIT(f)                       ((f) | (0x01)) 
#define  RESET_DBIT(f)                     ((f) & (~0x01))
 
//#define  SET_MPTR(f,b)                     (((f)<< 1) | (b)) // original
#define  SET_MPTR(f,b)					   (((f)<< 3) | (b)) // Modified

enum eReqFlags
  {
    HTS_REQ_FULL      = 0x01,
    HTS_REQ_QUEUED    = 0x02,
    HTS_REQ_SUBMITTED = 0x04,
    HTS_REQ_COMPLETED = 0x08,
    HTS_REQ_ABORTED   = 0x10,
    HTS_REQ_BLOCKING  = 0x20
  };

enum eReqType
  {
    HTS_REQ_TYPE_FIND   = 0x01,
    HTS_REQ_TYPE_ADD    = 0x02,
    HTS_REQ_TYPE_REMOVE = 0x04,
  };
// Added --> Nipuna
enum eRetVals 
	{
	/* return values for SNIP */
	HTS_SNIP_SUCCESS = 0x00,
	HTS_SNIP_FAILED = 0x01,
	HTS_NEXT_UNMARKED = 0x02,
	HTS_INVALID_START = 0x03,
	/* return values for REPLACE */
	HTS_REPLACE_SUCCESS = 0x00,
	HTS_REPLACE_FAILED = 0x04,
	HTS_INVALID_PBITS = 0x05,
	HTS_INVALID_NBITS = 0x06,
	HTS_RETAIN_FAILED = 0x07,
	/*return values for WINDOW*/
	HTS_KEY_FOUND = 0x00,
	HTS_WINDOW_FOUND = 0x08,
	HTS_INVALID_PREV_BITS = 0x09,
	HTS_INVALID_NEXT_REF = 0xA,
	HTS_WINDOW_NOT_FOUND = 0xB,
	HTS_INVALID_NEXT_BITS = 0xC
	} ;
#endif

