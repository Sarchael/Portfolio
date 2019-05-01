package com.spring.rest.controller;

import com.spring.rest.entity.Customer;
import com.spring.rest.exceptions.CustomerNotFoundException;
import com.spring.rest.service.CustomerService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/api")
public class CustomerRestController {

    @Autowired
    private CustomerService customerService;

    @GetMapping("/customers")
    public List<Customer> getCustomerList(){
        return customerService.getCustomers();
    }

    @GetMapping("/customers/{id}")
    public Customer getCustomerById(@PathVariable int id){
        Customer customer = customerService.getCustomer(id);
        if(customer==null)
            throw new CustomerNotFoundException("Customer with id: <" + id + "> not found");
        return customer;
    }

    @PostMapping("/customers")
    public Customer addCustomer(@RequestBody Customer customer){

        customer.setId(0); //if id==0 || id==null then query.saveOrUpdate method choose SAVE
        customerService.saveCustomer(customer);

        return customer;
    }

    @PutMapping("/customers")
    public Customer updateCustomer(@RequestBody Customer customer){
        if(customer.getId() == 0)
            throw new CustomerNotFoundException("ID cannot equals 0");
        customerService.saveCustomer(customer);
        return customer;
    }

    @DeleteMapping("/customers/{id}")
    public String deleteCustomer(@PathVariable int id){
        Customer customer = customerService.getCustomer(id);

        if(customer == null)
            throw new CustomerNotFoundException("Customer with id: <" + id + "> not found");

        customerService.deleteCustomer(id);

        return "Customer with id: <" + id + "> deleted succesfully";
    }
}
