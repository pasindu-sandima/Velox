Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// void OLEDsetup(){
//     if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
//         Serial.println(F("SSD1306 allocation failed"));
//     for(;;); // Don't proceed, loop forever
//   }
// }
// void OLEDprint(String word){
//   display.clearDisplay();
//   display.setTextSize(3);             // Normal 1:1 pixel scale
//   display.setTextColor(WHITE);        // Draw white text
//   display.setCursor(20,20);             // Start at top-left corner
//   display.print(word); 
//   display.display();

// }
void initialize_OLED()
{
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    { // Address 0x3C for 128x32
        for (;;)
            ; // Don't proceed, loop forever
    }
    display.display();
    delay(500); // Pause for 1/2 seconds
    display.clearDisplay();
    /*display.drawPixel(10, 10, WHITE);
    display.display();*/
    delay(100); // time before showing anything in the display
}

void OLED_Display(String text)
{
    display.clearDisplay();

    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(WHITE);
    display.setCursor(2, 2);
    display.println(text);
    display.display(); // Show initial text
    //delay(100);
}
void OLED_print(int value){
  String text= String(value);
  display.clearDisplay();

  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(WHITE);
  display.setCursor(2, 2);
  display.println(text);
  display.display();


}

void Print_Velox(){
  display.clearDisplay();
  display.setTextSize(3);             // Normal 1:1 pixel scale
  display.setTextColor(WHITE);        // Draw white text
  display.setCursor(20,20);             // Start at top-left corner
  display.print("VELOX"); 
  display.display();

}
void Print_Red(){
  display.clearDisplay();
  display.setTextSize(3);             // Normal 1:1 pixel scale
  display.setTextColor(WHITE);        // Draw white text
  display.setCursor(20,20);             // Start at top-left corner
  display.print("Red"); 
  display.display();

}
void Print_Blue(){
  display.clearDisplay();
  display.setTextSize(3);             // Normal 1:1 pixel scale
  display.setTextColor(WHITE);        // Draw white text
  display.setCursor(20,20);             // Start at top-left corner
  display.print("Blue"); 
  display.display();

}
