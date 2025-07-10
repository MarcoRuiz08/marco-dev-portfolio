package model;

import java.time.LocalDateTime;

public class ServiceRequest {
    private int id;
    private String description;
    private RequestStatus status;
    private LocalDateTime createdAt;
    private LocalDateTime lastUpdate;
    private String assignedTo;
    private Priority priority;
    private String clientName;


    //Constructor
    ServiceRequest() {

    }

    ServiceRequest(int idService, String descriptionService, RequestStatus statusService, LocalDateTime createdAtService, LocalDateTime lastUpdate, String assignedToService, Priority priorityService, String clientNameService) {
        this.id = idService;
        this.description = descriptionService;
        this.status = statusService;
        this.createdAt = createdAtService;
    }

    //Setters
    public void setId(int idService) {
        this.id = idService;
    }

    public void setDescription(String descriptionService) {
        this.description = descriptionService;
    }

    public void setStatus(RequestStatus statusService) {
        this.status = statusService;
    }

    public void setCreatedAt(LocalDateTime createdAtService) {
        this.createdAt = createdAtService;
    }

    //Getters
    public int getId() {
        return id;
    }

    public String getDescription() {
        return description;
    }

    public RequestStatus getStatus() {
        return status;
    }

    public LocalDateTime getCreatedAt() {
        return createdAt;
    }

    public LocalDateTime getLastUpdate() {
        return lastUpdate;
    }

    /*
    * tostring():
    *
    *[ID: 104] PENDING | "No se puede acceder al sistema SAP"
        Assigned to: Juan Pérez | Priority: HIGH
        Created: 2024-07-01 | Last Updated: 2024-07-02
        Client: Laura González
    * */
}
