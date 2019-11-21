
import 'package:flutter/material.dart';

//Must NOT return anything
void main() {
  runApp(MyApp());
}

//Alt + shift + f --> formatting
//ctrl + space --> intellisense

class MyApp extends StatelessWidget {
  void _flipImageOnBtPress() {
    
  }
  //when we pass object on to flatter (this case MyApp) it will first call build method
  //Every build method must return a widget
  //@orverride key is used to override functions
  @override
  Widget build(BuildContext context) {
    //MaterilApp can take arguments; that will "draw" stuff on the screen
    //MaterailApp is a wrapper around entier app
    //home: needs another widget that is drawn on screen
    //Scaffold is used to create a nice background on app
    return MaterialApp(
      home: Scaffold(
          //This is the display screen
          appBar: AppBar(
            title: Text('Here is List'), //Setting title
          ),
          body: Column(children: [
            Container(
              child: RaisedButton(
                child: Text("Add product"),
                onPressed: _flipImageOnBtPress,
              ),
              margin: EdgeInsets.all(5.0),
            ), //This will add button

            Card(
              child: Column(
                children: <Widget>[
                  Image.asset(".idea/assets/kids.jpg"), //This is Image widget and we are also createing a constructor out of it by saying ".asset"
                  Text("MyKids"),
                  //Image.asset(".idea/assets/jerry.jpg"),
                  //Text("Jerry")
                ],
              ),
            ),
          ])),
    );
  }
}
