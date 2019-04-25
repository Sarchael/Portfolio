/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package firmakurierska;

public class AllControllers {
 
    private static AllControllers INSTANCE;
 
    private AllControllers(){}

    private BorderPaneController borderPaneController;
    private HomePageController homePageController;
    private SecondTopMenuController secondTopMenuController;
    private SignInController signInController;
    private SignUpController signUpController;
    private TopMenuController topMenuController;
    private TracePackageController tracePackageController;
    private LandingPageController landingPageController;
    private PreviousPackagesController previousPackagesController;
    private SendPackageController sendPackageController;
    
    public BorderPaneController getBorderPaneController() {
        return borderPaneController;
    }

    public HomePageController getHomePageController() {
        return homePageController;
    }

    public SecondTopMenuController getSecondTopMenuController() {
        return secondTopMenuController;
    }

    public SignInController getSignInController() {
        return signInController;
    }

    public SignUpController getSignUpController() {
        return signUpController;
    }

    public TopMenuController getTopMenuController() {
        return topMenuController;
    }

    public TracePackageController getTracePackageController() {
        return tracePackageController;
    }

    public LandingPageController getLandingPageController() {
        return landingPageController;
    }

    public PreviousPackagesController getPreviousPackagesController() {
        return previousPackagesController;
    }

    public SendPackageController getSendPackageController() {
        return sendPackageController;
    }

    public void setSendPackageController(SendPackageController sendPackageController) {
        this.sendPackageController = sendPackageController;
    }

    public void setPreviousPackagesController(PreviousPackagesController previousPackagesController) {
        this.previousPackagesController = previousPackagesController;
    }

    public void setLandingPageController(LandingPageController landingPageController) {
        this.landingPageController = landingPageController;
    }

    public void setBorderPaneController(BorderPaneController borderPaneController) {
        this.borderPaneController = borderPaneController;
    }

    public void setHomePageController(HomePageController homePageController) {
        this.homePageController = homePageController;
    }

    public void setSecondTopMenuController(SecondTopMenuController secondTopMenuController) {
        this.secondTopMenuController = secondTopMenuController;
    }

    public void setSignInController(SignInController signInController) {
        this.signInController = signInController;
    }

    public void setSignUpController(SignUpController signUpController) {
        this.signUpController = signUpController;
    }

    public void setTopMenuController(TopMenuController topMenuController) {
        this.topMenuController = topMenuController;
    }

    public void setTracePackageController(TracePackageController tracePackageController) {
        this.tracePackageController = tracePackageController;
    }
    
    
    public static AllControllers getInstance(){
        if(INSTANCE==null)
            INSTANCE = new AllControllers();
        return INSTANCE;
    }
}
