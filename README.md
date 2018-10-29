# NTDirect32
> NodeJS Wrapper for the Ninja Trader 7 NtDirect.dll api

![][warning] This is a 32-bit windows only module, due to dll supporting only 32-bit

![][warning] You must install Ninja trader 7 in order to use this module (also must be running for interaction)

[![NPM version][npm-image]][npm-url]

Table of contents
=================

 * [What is it?](#what-is-it)
 * [Installation](#installation)
 * How to use it:
    * [Getting Started](#getting-started)
    * [Config](#config)
    * [Methods](#methods)
 * [How to contribute](#how-to-contribute)
 * [License](#license)

What is it?
==========
This library allows you to interact with the Ninja trader 7 application using the NtDirect.dll provided api.
You can view more details on this dll library in the Ninja Trader documentations: [Documentation](https://ninjatrader.com/support/helpGuides/nt7/?automated_trading_interface_at.htm)

Installation
============
This libray can be installed using:

 * [NPM](https://www.npmjs.com) :  `npm install ntdirect32 --save`
 
Getting started
============
This script can be loaded using Nodes require method
```
 var NTDirect = require("ntdirect32");
```

Config
==========
You may add a `config.json` to your projects root directory to configure a startup config or call the config method. Any method that requires one of these items allows leaving out that param and the default config will then just be used.

#### host
Host tells where the application is located. default is `localhost`

#### port
Port tells which port to find the application on. default is `36973`

#### account
Account is the account that you will be using for trading. __Required, no default__

#### instrument
Instrument is the name of the instrument you would like to use by default. __Required, no default__

#### Example Config

```
{
  "host": "192.168.0.205",
  "port": 1337,
  "account": "Continuum",
  "instrument": "ES"
}
```

Methods
==========
The public methods that are available in the library

#### ask (instrument (string)(optional), price (number), size (number))
Sets the last price and size for the specified instrument. A return value of 1 indicates success and 0 indicates an error.

#### askPlayback (instrument (string)(optional), price (number), size (number), timestamp (Date Object))
Sets the ask price and size for the specified instrument for use when synchronizing NinjaTrader playback with an external application playback. A return value of 1 indicates success and 0 indicates an error.

#### avgEntryPrice (instrument (string)(optional), account (string)(optional))
Gets the average entry price for the specified instrument/account combination.

#### avgFillPrice (order id (string))
Gets the average entry price for the specified orderId.

#### bid (instrument (string)(optional), price (number), size (number))
Sets the bid price and size for the specified instrument. A return value of 1 indicates success and 0 indicates an error.

#### bidPlayback (instrument (string)(optional), price (number), size (number), timestamp (Date Object))
Sets the bid price and size for the specified instrument for use when synchronizing NinjaTrader playback with an external application playback. A return value of 1 indicates success and 0 indicates an error.

#### buyingPower (account (string)(optional))
Gets the buying power for the specified account. *Not all brokerage technologies support this value.

#### cashValue (account (string)(optional))
Gets the cash value for the specified account. *Not all brokerage technologies support this value.

#### cancelAllOrders ()
This will cancel all active orders across all accounts and broker connections.

#### flattenEverything ()
This will cancel all active orders and flatten all positions across all accounts and broker connections.

#### closeStrategy (strategy id (string))
This will close an ATM Strategy. The strategy ID value must match a strategy ID given to a strategy in the placeOrder method. This will close the specified strategy.

#### closePosition (Account (string)(optional), Instrument (string)(optional))
This will close a position. The instrument name value is the name of the NinjaTrader instrument including the exchange name. For equities, the symbol is sufficient. This will cancel any working orders and flatten the position.

#### cancelOrder (order id (string), strategy id (string)(optional))
This will cancel an order. The order ID value must match either the order ID value given to an order placed through the placeBuyOrder/placeSellOrder command or, an order name such as ENTRY*, EXIT*, STOP*, SIMSTOP* or TARGET*. The star (*) represents an integer value such as TARGET1 or TARGET2. Order names are only valid if a valid strategy ID value is passed. The strategy ID value must match a strategy ID value given to a strategy in the placeBuyOrder/placeSellOrder method.

#### changeOrder (order id (string), quantity (number)(optional), limitprice (number)(optional), stopprice (number)(optional), strategy id (string)(optional))
This will change the parameters of an order. The order ID value must match either the order ID value given to an order placed through the placeBuyOrder/placeSellOrder method or, an order name such as ENTRY*, EXIT*, STOP*, SIMSTOP* or TARGET*. The star (*) represents an integer value such as TARGET1 or TARGET2. Order names are only valid if a valid strategy ID value is passed. Pass in zero (0) values for limitprice, stopprice and quantity if you do not wish to change these order parameters. Price values must be in US decimal format (1212.25 is correct while 1212,25 is not).

#### placeBuyOrder (account (string), instrument (string), quantity (number), order type (string)(MARKET|LIMIT|STOP|STOPLIMIT), TIF (string)(DAY|GTC), limitprice (number)(optional), stopprice (number)(optional), oco (string)(optional), order id (string)(optional), strategy (string)(optional), strategy id (string)(optional))
This will place a buy order, place orders that initiate a NinjaTrader ATM Strategy, or place orders that are applied to an active NinjaTrader position ATM Strategy. Providing the optional strategy name field with a valid ATM Strategy template name will result in execution of that ATM Strategy once the order is partially or completely filled. Pass in an optional unique string value for the strategy ID in order to reference that ATM Strategy via other commands. To apply an order to an active ATM Strategy (existing strategies Stop Loss and Profit Target orders are amended) pass in the active strategy ID value and leave the strategy name field blank. Pass in an optional unique string value for the order ID in order to reference that order via other methods. If specifying an ATM Strategy template name, there is no need to pass in an order ID as the strategy based orders can be referenced by their internally generated names such as TARGET1, STOP1 and so on.

#### placeSellOrder (account (string), instrument (string), quantity (number), order type (string)(MARKET|LIMIT|STOP|STOPLIMIT), TIF (string)(DAY|GTC), limitprice (number)(optional), stopprice (number)(optional), oco (string)(optional), order id (string)(optional), strategy (string)(optional), strategy id (string)(optional))
This will place a sell order, place orders that initiate a NinjaTrader ATM Strategy, or place orders that are applied to an active NinjaTrader position ATM Strategy. Providing the optional strategy name field with a valid ATM Strategy template name will result in execution of that ATM Strategy once the order is partially or completely filled. Pass in an optional unique string value for the strategy ID in order to reference that ATM Strategy via other commands. To apply an order to an active ATM Strategy (existing strategies Stop Loss and Profit Target orders are amended) pass in the active strategy ID value and leave the strategy name field blank. Pass in an optional unique string value for the order ID in order to reference that order via other methods. If specifying an ATM Strategy template name, there is no need to pass in an order ID as the strategy based orders can be referenced by their internally generated names such as TARGET1, STOP1 and so on.

#### reverseBuyPosition (account (string), instrument (string), quantity (number), order type (string)(MARKET|LIMIT|STOP|STOPLIMIT), TIF (string)(DAY|GTC), limitprice (number)(optional), stopprice (number)(optional), oco (string)(optional), order id (string)(optional), strategy (string)(optional), strategy id (string)(optional))
This will close the current position and place an order in the opposite direction. The field requirements are identical to the placeBuyOrder method.

#### reverseSellPosition (account (string), instrument (string), quantity (number), order type (string)(MARKET|LIMIT|STOP|STOPLIMIT), TIF (string)(DAY|GTC), limitprice (number)(optional), stopprice (number)(optional), oco (string)(optional), order id (string)(optional), strategy (string)(optional), strategy id (string)(optional))
This will close the current position and place an order in the opposite direction. The field requirements are identical to the placeSellOrder method.

#### confirmOrders (confirm (bool))
The parameter confirm indicates if an order confirmation message will appear. This toggles the global option that can be set manually in the NinjaTrader Control Center by selecting the Tools menu and the menu item Options, then checking the "Confirm order placement" checkbox.

#### connected (showMessage (bool))
Returns a value of 1 if a connection has been established to the NinjaTrader server (application) and if the ATI is currently enabled or, 0 if it is disconnected. Calling any function in the library will automatically initiate a connection to the server. The parameter showMessage indicates if a message box is displayed in case the connection cannot be established.

#### filled (order id (string))
Gets the number of contracts/shares filled for the orderId.

#### last (instrument (string)(optional), price (number), size (number))
Sets the last price and size for the specified instrument. A return value of 1 indicates success and 0 indicates an error.

#### lastPlayback (instrument (string)(optional), price (number), size (number), timestamp (Date Object))
Sets the last price and size for the specified instrument for use when synchronizing NinjaTrader playback with an external application playback. A return value of 1 indicates success and 0 indicates an error.

#### marketData (instrument (string)(optional), type (string)(last|bid|ask))
Gets the most recent price for the specified instrument and data type. last, bid, ask. You must first call the instrument(instrument (string)) or subscribeMarketData(instrument (string)(optional)) functions prior to calling this function.

#### marketPosition (instrument (string)(optional), account (string)(optional))
Gets the market position for an instrument/account combination. Returns flat, short, or long.

#### newOrderId ()
Creates a new unique order ID.

#### orderStatus (order id (string))
Gets the order state (Initialized|PendingSubmit|Accepted|Working|PendingChange|PendingCancel|Cancelled|Rejected|PartFilled|Filled) for the orderId. Returns an empty string if the order ID value provided does not return an order.

#### realizedPnL (account (string)(optional))
Gets the realized profit and loss of an account.

#### setUp (host (string)(optional), port (number)(optional))
Optional function to set the host and port number. The default port number can be set via the General tab under Options. If you change these default values, this function must be called before any other function. A return value of 1 indicates success and 0 indicates an error.

#### stopOrders (strategy id (string))
returns an array of order ID's of all Stop Loss orders of an ATM Strategy. Internal token ID value is used since it is guaranteed to be unique.

#### strategies (account (string)(optional))
Gets an array of strategy ID's of all ATM Strategies of an account. Duplicate ID values can be returned if strategies were initiated outside of the ATI.

#### strategyPosition (strategy id (string))
Gets the position for a strategy. Returns flat, short, or long.

#### subscribeMarketData (instrument ((string)|(array[string]))(optional))
Starts a market data stream for the specific instrument or instruments. Call the MarketData() function to retrieve prices. Make sure you call the UnSubscribeMarketData() function to close the data stream. A return value of 1 indicates success and 0 indicates an error. subscribeMarketData is also called when the instrument config default is set.

#### targetOrders (strategy id (string))
Gets an array of order ID's of all Profit Target orders of an ATM Strategy. Internal token ID value is used since it is guaranteed to be unique.

#### tearDown ()
Disconnects the DLL from the NinjaTrader server. A return value of 1 indicates success and 0 indicates an error. This automatically happens when node crashes or exits.

#### unsubscribeMarketData(instrument ((string)|(array[string]))(optional))
Stops a market data stream for the specific instrument or instruments. A return value of 1 indicates success and 0 indicates an error. unsubscribeMarketData is also called when the instrument config changes the default instrument.

How to contribute
============
If You would like to contribute here are the steps

1. Clone Repo: [NTDirect32 Github Repo](https://github.com/keleko34/NTDirect32-NodeJS)
2. Install any necessary dev dependencies `npm i`
3. build the project `npm run rebuild` or for debug `npm run rebuild:dev`
4. test your changes don't break anything
5. Make a pull request on github for your changes

License
============
You can view the license here: [License](https://github.com/keleko34/NTDirect32-NodeJS/blob/master/LICENSE)

[warning]: https://cdn2.iconfinder.com/data/icons/aspneticons_v1.0_Nov2006/attention3_16x16.gif
[npm-url]: https://www.npmjs.com/package/ntdirect32
[npm-image]: https://img.shields.io/npm/v/ntdirect32.svg