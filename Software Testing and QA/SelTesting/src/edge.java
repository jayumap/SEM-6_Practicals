import org.openqa.selenium.By;
//import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.edge.EdgeDriver;

public class edge {
    public static void main(String[] args) throws InterruptedException{
    // TODO Auto-generated method stub
		
		System.out.println("TESTING");
		System.setProperty("webdriver.edge.driver", "D://Web Drivers//Edge Driver//edgedriver_win64//msedgedriver.exe");
		EdgeDriver driver = new EdgeDriver();
		Thread.sleep(1000);
		driver.get("https://www.facebook.com/");
		driver.findElement(By.id("email")).sendKeys("");
        driver.findElement(By.id("pass")).sendKeys("");
		driver.findElement(By.name("login")).click();
    } 
}
