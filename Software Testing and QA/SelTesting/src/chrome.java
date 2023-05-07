import org.openqa.selenium.By;
import org.openqa.selenium.chrome.ChromeDriver;
//import org.openqa.selenium.edge.EdgeDriver;

public class chrome {
	public static void main(String[] args) throws InterruptedException{
		System.out.println("TESTING");
		System.setProperty("webdriver.chrome.driver","D://Web Drivers//Chrome Driver//chromedriver_win32//chromedriver.exe");
		ChromeDriver driver = new ChromeDriver();
		driver.get("https://www.facebook.com/");
		Thread.sleep(1000);
		driver.findElement(By.id("email")).sendKeys("");
        driver.findElement(By.id("pass")).sendKeys("");
		driver.findElement(By.name("login")).click();
		driver.get("https://www.youtube.com/");
	}
}

