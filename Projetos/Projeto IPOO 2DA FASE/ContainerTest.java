

import static org.junit.Assert.*;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

/**
 * The test class ContainerTest.
 *
 * @author  (your name)
 * @version (a version number or a date)
 */
public class ContainerTest
{
    /**
     * Default constructor for test class ContainerTest
     */
    public ContainerTest()
    {
    }

    /**
     * Sets up the test fixture.
     *
     * Called before every test case method.
     */
    @Before
    public void setUp()
    {
    }

    /**
     * Tears down the test fixture.
     *
     * Called after every test case method.
     */
    @After
    public void tearDown()
    {
    }

    @Test
    public void checkContainer()
    {
        Container containe1 = new Container(false, 123);
        Container containe2 = new Container(true, 1234);
        assertNotNull(containe1.getProducts());
        assertNotNull(containe2.getProducts());
        assertEquals(22000, containe2.getCargoLeft(), 0.1);
        assertEquals(22000, containe1.getCargoLeft(), 0.1);
    }
}

