/* Available Parameters and Valid Values
PARAMETERS            VALID VALUES

COMMAND               CANCEL, CANCELALLORDERS, CHANGE, CLOSEPOSITION, CLOSESTRATEGY, FLATTENEVERYTHING, 
                      PLACE, REVERSEPOSITION

ACCOUNT               The name of the account the command is to be processed

INSTRUMENT            Instrument name

ACTION                BUY, SELL

QTY                   Any integer value

ORDER TYPE            MARKET, LIMIT, STOP, STOPLIMIT

LIMIT PRICE           Any decimal value (use decimals not commas 1212.25 for example)

STOP PRICE            Any decimal value

TIF                   DAY, GTC

OCO ID                Any string value

ORDER ID              Any string value (must be unique for each line/file)

STRATEGY              Strategy template name (must exist in NinjaTrader)

STRATEGY ID           Any string value (must be unique for each line/file)

The following table displays required (R) and optional (O) values for each different command value.

CANCEL: R:ORDER ID O:STRATEGY ID

CANCELALLORDERS: None

CHANGE: O:QTY O:LIMIT PRICE O:STOP PRICE R:ORDER ID O:STRATEGY ID

CLOSEPOSITION: R:ACCOUNT R:INSTRUMENT

CLOSESTRATEGY: R:STRATEGY ID

FLATTENEVERYTHING: None

PLACE: R:ACCOUNT R:INSTRUMENT R:ACTION R:QTY R:ORDER TYPE O:LIMIT PRICE O:STOP PRICE R:TIF O:OCO ID O: ORDER ID O:STRATEGY O:STRATEGY ID

REVERSEPOSITION: R:ACCOUNT R:INSTRUMENT R:ACTION R:QTY R:ORDER TYPE O:LIMIT PRICE O:STOP PRICE R:TIF O:OCO ID O: ORDER ID O:STRATEGY O:STRATEGY ID

Following are the descriptions of each available command.

CANCEL COMMAND
This command will cancel an order and requires an order ID value and an optional strategy ID value. The order ID value must match either the order ID value given to an order placed through the PLACE command or, an order name such as ENTRY*, EXIT*, STOP*, SIMSTOP* or TARGET*. The star (*) represents an integer value such as TARGET1 or TARGET2. Order names are only valid if a valid strategy ID value is passed. The strategy ID value must match a strategy ID value given to a strategy in the PLACE command.

CANCELALLORDERS COMMAND 
This command will cancel all active orders across all accounts and broker connections.

CHANGE COMMAND
This command will change the parameters of an order and requires an order ID value, optional price and quantity values and an optional strategy ID value. The order ID value must match either the order ID value given to an order placed through the PLACE command or, an order name such as ENTRY*, EXIT*, STOP*, SIMSTOP* or TARGET*. The star (*) represents an integer value such as TARGET1 or TARGET2. Order names are only valid if a valid strategy ID value is passed. Pass in zero (0) values for price and quantity if you do not wish to change these order parameters. Price values must be in US decimal format (1212.25 is correct while 1212,25 is not).

CLOSEPOSITION COMMAND
This command will close a position and requires an account name value and an instrument name value. The instrument name value is the name of the NinjaTrader instrument including the exchange name. For equities, the symbol is sufficient. This command will cancel any working orders and flatten the position.

CLOSESTRATEGY COMMAND
This command will close an ATM Strategy and requires a strategy ID value. The strategy ID value must match a strategy ID given to a strategy in the PLACE command. This command will close the specified strategy.

FLATTENEVERYTHING COMMAND
This command will cancel all active orders and flatten all positions across all accounts and broker connections.

PLACE COMMAND
This command will place orders, place orders that initiate a NinjaTrader ATM Strategy, or place orders that are applied to an active NinjaTrader position ATM Strategy. Providing the optional strategy name field with a valid ATM Strategy template name will result in execution of that ATM Strategy once the order is partially or completely filled. Pass in an optional unique string value for the strategy ID in order to reference that ATM Strategy via other commands. To apply an order to an active ATM Strategy (existing strategies Stop Loss and Profit Target orders are amended) pass in the active strategy ID value and leave the strategy name field blank. Pass in an optional unique string value for the order ID in order to reference that order via other commands. If specifying an ATM Strategy template name, there is no need to pass in an order ID as the strategy based orders can be referenced by their internally generated names such as TARGET1, STOP1 and so on.

REVERSEPOSITION COMMAND
This command will close the current position and place an order in the opposite direction. The field requirements are identical to the PLACE command.

Order State   Definition   Color Code

Initialized   Order information validated on local PC  Yellow

PendingSubmit  Order submitted to the connectivity provider  Orange

Accepted  Order confirmation received by broker  Light blue

Working  Order confirmation received by exchange  Green

PendingChange  Order modification submitted to the connectivity provider  Orange

PendingCancel  Order cancellation submitted to the connectivity provider/exchange  Red

Cancelled  Order cancellation confirmed cancelled by exchange  Red

Rejected  Order rejected locally, by connectivity provider or exchange  Red

PartFilled  Order partially filled  Red

Filled  Order completely filled  Green

*/

extern "C"
{
  /* Sets the last price and size for the specified instrument. A return value of 0 indicates success and -1 indicates an error. */
  int __stdcall Ask(char* instrument, double price, int size);
  
  /* Sets the ask price and size for the specified instrument for use when synchronizing NinjaTrader playback with an external application playback. A return value of 0 indicates success and -1 indicates an error. The timestamp parameter format is "yyyyMMddhhmmss". */
  int __stdcall AskPlayback(char* instrument, double price, int size, char* timestamp);
  
  /* Gets the average entry price for the specified instrument/account combination. */
  double __stdcall AvgEntryPrice(char* instrument, char* account);
  
  /* Gets the average entry price for the specified orderId. */
  double __stdcall AvgFillPrice(char* orderId);
  
  /* Sets the bid price and size for the specified instrument. A return value of 0 indicates success and -1 indicates an error. */
  int __stdcall Bid(char* instrument, double price, int size);
  
  /* Sets the bid price and size for the specified instrument for use when synchronizing NinjaTrader playback with an external application playback. A return value of 0 indicates success and -1 indicates an error. The timestamp parameter format is "yyyyMMddhhmmss". */
  int __stdcall BidPlayback(char* instrument, double price, int size, char* timestamp);
  
  /* Gets the buying power for the specified account. *Not all brokerage technologies support this value. */
  double __stdcall BuyingPower(char* account);
  
  /* Gets the cash value for the specified account. *Not all brokerage technologies support this value. */
  double __stdcall CashValue(char* account);
  
  /* Function for submitting, cancelling and changing orders, positions and strategies. Refer to the Commands and Valid Parameters section for detailed information. A return value of 0 indicates success and -1 indicates an error. The Log tab will list context sensitive error information. */
  int __stdcall Command(char* command, char* account = NULL, char* instrument = NULL, char* action = NULL, int quantity = NULL, char* orderType = NULL, double limitPrice = NULL, double stopPrice = NULL, char* timeInForce = NULL, char* oco = NULL, char* orderId = NULL, char* strategy = NULL, char* strategyId = NULL);
  
  /* The parameter confirm indicates if an order confirmation message will appear. This toggles the global option that can be set manually in the NinjaTrader Control Center by selecting the Tools menu and the menu item Options, then checking the "Confirm order placement" checkbox. A value of 1 sets this option to true, any other value sets this option to false. */
  int __stdcall ConfirmOrders(int confirm);
  
  /* Returns a value of zero if the DLL has established a connection to the NinjaTrader server (application) and if the ATI is currently enabled or, -1 if it is disconnected. Calling any function in the DLL will automatically initiate a connection to the server. The parameter showMessage indicates if a message box is displayed in case the connection cannot be established. A value of 1 = show message box, any other value = don't show message box. */
  int __stdcall Connected(int showMessage);
  
  /* Gets the number of contracts/shares filled for the orderId. */
  int __stdcall Filled(char* orderId);
  
  /* Sets the last price and size for the specified instrument. A return value of 0 indicates success and -1 indicates an error. */
  int __stdcall Last(char* instrument, double price, int size);
    
  /* Sets the last price and size for the specified instrument for use when synchronizing NinjaTrader playback with an external application playback. A return value of 0 indicates success and -1 indicates an error. The timestamp parameter format is "yyyyMMddhhmmss". */
  int __stdcall LastPlayback(char* instrument, double price, int size, char* timestamp);
  
  /* Gets the most recent price for the specified instrument and data type. 0 = last, 1 = bid, 2 = ask. You must first call the SubscribeMarketData() function prior to calling this function. */
  double __stdcall MarketData(char* instrument, int type);
  
  /* Gets the market position for an instrument/account combination. Returns 0 for flat, negative value for short positive value for long. */
  int __stdcall MarketPosition(char* instrument, char* account);
  
  /* Gets a new unique order ID value. */
  char* __stdcall NewOrderId(void);
  
  /* Gets the order state (see definitions) for the orderId. Returns an empty string if the order ID value provided does not return an order. */
  char* __stdcall OrderStatus(char* orderId);
  
  /* Gets the realized profit and loss of an account. */
  double __stdcall RealizedPnL(char* account);
  
  /* Optional function to set the host and port number. By default, host is set to "localhost" and port is set to 36973. The default port number can be set via the General tab under Options. If you change these default values, this function must be called before any other function. A return value of 0 indicates success and -1 indicates an error. */
  int __stdcall SetUp(char* host, int port);
  
  /* Gets a string of order ID's of all Stop Loss orders of an ATM Strategy separated by '|'. Internal token ID value is used since it is guaranteed to be unique. */
  char* __stdcall StopOrders(char* strategyId);
  
  /* Gets a string of strategy ID's of all ATM Strategies of an account separated by '|'. Duplicate ID values can be returned if strategies were initiated outside of the ATI. */
  char*__stdcall Strategies(char* account);
  
  /* Gets the position for a strategy. Returns 0 for flat, negative value for short and positive value for long.  */
  int __stdcall StrategyPosition(char* strategyId);
  
  /* Starts a market data stream for the specific instrument. Call the MarketData() function to retrieve prices. Make sure you call the UnSubscribeMarketData() function to close the data stream. A return value of 0 indicates success and -1 indicates an error. */
  int __stdcall SubscribeMarketData(char* instrument);
  
  /* Gets a string of order ID's of all Profit Target orders of an ATM Strategy separated by '|'. Internal token ID value is used since it is guaranteed to be unique. */
  char* __stdcall TargetOrders(char* strategyId);
  
  /* Disconnects the DLL from the NinjaTrader server. A return value of 0 indicates success and -1 indicates an error. */
  int __stdcall TearDown(void);
  
  /* Stops a market data stream for the specific instrument. A return value of 0 indicates success and -1 indicates an error. */
  int __stdcall UnsubscribeMarketData(char* instrument);
  
}
