/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Modele;

/**
 *
 * @author Michal
 */
public class PackagesHistory {
    private final String packageNumber;
    private final String receiver;
    private final String status;
    private final String postingDate;
    private final String deliveryDate;

    public PackagesHistory(String packageNumber, String receiver, String status, String postingDate, String deliveryDate) {
        this.packageNumber = packageNumber;
        this.receiver = receiver;
        this.status = status;
        this.postingDate = postingDate;
        this.deliveryDate = deliveryDate;
    }

    public String getPackageNumber() {
        return packageNumber;
    }

    public String getReceiver() {
        return receiver;
    }

    public String getStatus() {
        return status;
    }

    public String getPostingDate() {
        return postingDate;
    }

    public String getDeliveryDate() {
        return deliveryDate;
    }
    
}
