/*==============================================================*/
/* DBMS name:      Microsoft SQL Server 2008                    */
/* Created on:     12/8/2018 9:40:44 AM                         */
/*==============================================================*/


if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('CHEF') and o.name = 'FK_CHEF_INHERITAN_STAFF')
alter table CHEF
   drop constraint FK_CHEF_INHERITAN_STAFF
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('CLEANER') and o.name = 'FK_CLEANER_INHERITAN_STAFF')
alter table CLEANER
   drop constraint FK_CLEANER_INHERITAN_STAFF
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('CLEANER_ROOM') and o.name = 'FK_CLEANER__CLEANER_R_ROOM')
alter table CLEANER_ROOM
   drop constraint FK_CLEANER__CLEANER_R_ROOM
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('CLEANER_ROOM') and o.name = 'FK_CLEANER__CLEANER_R_CLEANER')
alter table CLEANER_ROOM
   drop constraint FK_CLEANER__CLEANER_R_CLEANER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('FOOD') and o.name = 'FK_FOOD_ORDER_CHE_CHEF')
alter table FOOD
   drop constraint FK_FOOD_ORDER_CHE_CHEF
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('FOODORDER') and o.name = 'FK_FOODORDE_CUSTOMER__CUSTOMER')
alter table FOODORDER
   drop constraint FK_FOODORDE_CUSTOMER__CUSTOMER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('INVOICE') and o.name = 'FK_INVOICE_CUSTOMER__CUSTOMER')
alter table INVOICE
   drop constraint FK_INVOICE_CUSTOMER__CUSTOMER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('INVOICE') and o.name = 'FK_INVOICE_INVOICE_R_RECEPTIO')
alter table INVOICE
   drop constraint FK_INVOICE_INVOICE_R_RECEPTIO
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('INVOICE') and o.name = 'FK_INVOICE_INVOICE_S_FOODORDE')
alter table INVOICE
   drop constraint FK_INVOICE_INVOICE_S_FOODORDE
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('INVOICE') and o.name = 'FK_INVOICE_INVOICE_S_RESERVAT')
alter table INVOICE
   drop constraint FK_INVOICE_INVOICE_S_RESERVAT
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('OPERATINGCOST') and o.name = 'FK_OPERATIN_BRANCH_OP_BRANCH')
alter table OPERATINGCOST
   drop constraint FK_OPERATIN_BRANCH_OP_BRANCH
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('RECEPTIONIST') and o.name = 'FK_RECEPTIO_INHERITAN_STAFF')
alter table RECEPTIONIST
   drop constraint FK_RECEPTIO_INHERITAN_STAFF
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('REGISTER') and o.name = 'FK_REGISTER_STAFF_REG_STAFF')
alter table REGISTER
   drop constraint FK_REGISTER_STAFF_REG_STAFF
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('RENTEDROOM') and o.name = 'FK_RENTEDRO_ASSIGN_RECEPTIO')
alter table RENTEDROOM
   drop constraint FK_RENTEDRO_ASSIGN_RECEPTIO
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('RENTEDROOM') and o.name = 'FK_RENTEDRO_ASSIGNED__ROOM')
alter table RENTEDROOM
   drop constraint FK_RENTEDRO_ASSIGNED__ROOM
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('RENTEDROOM') and o.name = 'FK_RENTEDRO_CONTAIN2_RESERVAT')
alter table RENTEDROOM
   drop constraint FK_RENTEDRO_CONTAIN2_RESERVAT
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('RESERVATION') and o.name = 'FK_RESERVAT_CUSTOMER__CUSTOMER')
alter table RESERVATION
   drop constraint FK_RESERVAT_CUSTOMER__CUSTOMER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('ROOM') and o.name = 'FK_ROOM_BRANCH_RO_BRANCH')
alter table ROOM
   drop constraint FK_ROOM_BRANCH_RO_BRANCH
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('STAFF') and o.name = 'FK_STAFF_BRANCH_ST_BRANCH')
alter table STAFF
   drop constraint FK_STAFF_BRANCH_ST_BRANCH
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('STAFF') and o.name = 'FK_STAFF_MANAGER_STAFF')
alter table STAFF
   drop constraint FK_STAFF_MANAGER_STAFF
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('USINGFOOD') and o.name = 'FK_USINGFOO_CONTAIN_FOOD')
alter table USINGFOOD
   drop constraint FK_USINGFOO_CONTAIN_FOOD
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('USINGFOOD') and o.name = 'FK_USINGFOO_CONTAIN3_FOODORDE')
alter table USINGFOOD
   drop constraint FK_USINGFOO_CONTAIN3_FOODORDE
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('USINGFOOD') and o.name = 'FK_USINGFOO_SERVED_RECEPTIO')
alter table USINGFOOD
   drop constraint FK_USINGFOO_SERVED_RECEPTIO
go

if exists (select 1
            from  sysobjects
           where  id = object_id('BRANCH')
            and   type = 'U')
   drop table BRANCH
go

if exists (select 1
            from  sysobjects
           where  id = object_id('CHEF')
            and   type = 'U')
   drop table CHEF
go

if exists (select 1
            from  sysobjects
           where  id = object_id('CLEANER')
            and   type = 'U')
   drop table CLEANER
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('CLEANER_ROOM')
            and   name  = 'CLEANER_ROOM_FK'
            and   indid > 0
            and   indid < 255)
   drop index CLEANER_ROOM.CLEANER_ROOM_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('CLEANER_ROOM')
            and   name  = 'CLEANER_ROOM2_FK'
            and   indid > 0
            and   indid < 255)
   drop index CLEANER_ROOM.CLEANER_ROOM2_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('CLEANER_ROOM')
            and   type = 'U')
   drop table CLEANER_ROOM
go

if exists (select 1
            from  sysobjects
           where  id = object_id('CUSTOMER')
            and   type = 'U')
   drop table CUSTOMER
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('FOOD')
            and   name  = 'ORDER_CHEF_FK'
            and   indid > 0
            and   indid < 255)
   drop index FOOD.ORDER_CHEF_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('FOOD')
            and   type = 'U')
   drop table FOOD
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('FOODORDER')
            and   name  = 'CUSTOMER_SERVICE_FK'
            and   indid > 0
            and   indid < 255)
   drop index FOODORDER.CUSTOMER_SERVICE_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('FOODORDER')
            and   type = 'U')
   drop table FOODORDER
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('INVOICE')
            and   name  = 'INVOICE_SERVICE2_FK'
            and   indid > 0
            and   indid < 255)
   drop index INVOICE.INVOICE_SERVICE2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('INVOICE')
            and   name  = 'INVOICE_RECEPTIONIST_FK'
            and   indid > 0
            and   indid < 255)
   drop index INVOICE.INVOICE_RECEPTIONIST_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('INVOICE')
            and   name  = 'CUSTOMER_INVOICE_FK'
            and   indid > 0
            and   indid < 255)
   drop index INVOICE.CUSTOMER_INVOICE_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('INVOICE')
            and   type = 'U')
   drop table INVOICE
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('OPERATINGCOST')
            and   name  = 'BRANCH_OPERATIONCOST_FK'
            and   indid > 0
            and   indid < 255)
   drop index OPERATINGCOST.BRANCH_OPERATIONCOST_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('OPERATINGCOST')
            and   type = 'U')
   drop table OPERATINGCOST
go

if exists (select 1
            from  sysobjects
           where  id = object_id('RECEPTIONIST')
            and   type = 'U')
   drop table RECEPTIONIST
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('REGISTER')
            and   name  = 'STAFF_REGISTER2_FK'
            and   indid > 0
            and   indid < 255)
   drop index REGISTER.STAFF_REGISTER2_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('REGISTER')
            and   type = 'U')
   drop table REGISTER
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('RENTEDROOM')
            and   name  = 'ASSIGNED_TO_FK'
            and   indid > 0
            and   indid < 255)
   drop index RENTEDROOM.ASSIGNED_TO_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('RENTEDROOM')
            and   name  = 'ASSIGN_FK'
            and   indid > 0
            and   indid < 255)
   drop index RENTEDROOM.ASSIGN_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('RENTEDROOM')
            and   name  = 'CONTAIN2_FK'
            and   indid > 0
            and   indid < 255)
   drop index RENTEDROOM.CONTAIN2_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('RENTEDROOM')
            and   type = 'U')
   drop table RENTEDROOM
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('RESERVATION')
            and   name  = 'CUSTOMER_SERVICE2_FK'
            and   indid > 0
            and   indid < 255)
   drop index RESERVATION.CUSTOMER_SERVICE2_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('RESERVATION')
            and   type = 'U')
   drop table RESERVATION
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('ROOM')
            and   name  = 'BRANCH_ROOM_FK'
            and   indid > 0
            and   indid < 255)
   drop index ROOM.BRANCH_ROOM_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('ROOM')
            and   type = 'U')
   drop table ROOM
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('STAFF')
            and   name  = 'MANAGER_FK'
            and   indid > 0
            and   indid < 255)
   drop index STAFF.MANAGER_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('STAFF')
            and   name  = 'BRANCH_STAFF_FK'
            and   indid > 0
            and   indid < 255)
   drop index STAFF.BRANCH_STAFF_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('STAFF')
            and   type = 'U')
   drop table STAFF
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('USINGFOOD')
            and   name  = 'SERVED_FK'
            and   indid > 0
            and   indid < 255)
   drop index USINGFOOD.SERVED_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('USINGFOOD')
            and   name  = 'CONTAIN_FK'
            and   indid > 0
            and   indid < 255)
   drop index USINGFOOD.CONTAIN_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('USINGFOOD')
            and   name  = 'CONTAIN3_FK'
            and   indid > 0
            and   indid < 255)
   drop index USINGFOOD.CONTAIN3_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('USINGFOOD')
            and   type = 'U')
   drop table USINGFOOD
go

/*==============================================================*/
/* Table: BRANCH                                                */
/*==============================================================*/
create table BRANCH (
   BRANCHID             char(50)             not null,
   PHONE_NUMBER         int                  null,
   ADDRESSBRANCH        char(200)            null,
   BRANCHNAME           char(50)             null,
   constraint PK_BRANCH primary key nonclustered (BRANCHID)
)
go

/*==============================================================*/
/* Table: CHEF                                                  */
/*==============================================================*/
create table CHEF (
   STAFFID              char(50)             not null,
   BRANCHID             char(50)             not null,
   MNGID                char(50)             not null,
   ADDRESSSTAFF         char(200)            null,
   NAMESTAFF            char(50)             null,
   AGESTAFF             int                  null,
   STARTINGDATE         datetime             null,
   SALARY               int                  null,
   POSSITION            char(50)             null,
   STAFFGENDER          bit                  null,
   constraint PK_CHEF primary key nonclustered (STAFFID)
)
go

/*==============================================================*/
/* Table: CLEANER                                               */
/*==============================================================*/
create table CLEANER (
   STAFFID              char(50)             not null,
   BRANCHID             char(50)             not null,
   MNGID                char(50)             not null,
   ADDRESSSTAFF         char(200)            null,
   NAMESTAFF            char(50)             null,
   AGESTAFF             int                  null,
   STARTINGDATE         datetime             null,
   SALARY               int                  null,
   POSSITION            char(50)             null,
   STAFFGENDER          bit                  null,
   constraint PK_CLEANER primary key nonclustered (STAFFID)
)
go

/*==============================================================*/
/* Table: CLEANER_ROOM                                          */
/*==============================================================*/
create table CLEANER_ROOM (
   STAFFID              char(50)             not null,
   ROOMDID              int                  not null,
   constraint PK_CLEANER_ROOM primary key nonclustered (STAFFID, ROOMDID)
)
go

/*==============================================================*/
/* Index: CLEANER_ROOM2_FK                                      */
/*==============================================================*/
create index CLEANER_ROOM2_FK on CLEANER_ROOM (
STAFFID ASC
)
go

/*==============================================================*/
/* Index: CLEANER_ROOM_FK                                       */
/*==============================================================*/
create index CLEANER_ROOM_FK on CLEANER_ROOM (
ROOMDID ASC
)
go

/*==============================================================*/
/* Table: CUSTOMER                                              */
/*==============================================================*/
create table CUSTOMER (
   IDENTIFICATION       char(50)             not null,
   CUSGENDER            bit                  null,
   CUSADDRESS           char(200)            null,
   CUSAGE               int                  null,
   CUSNAME              char(100)            null,
   constraint PK_CUSTOMER primary key nonclustered (IDENTIFICATION)
)
go

/*==============================================================*/
/* Table: FOOD                                                  */
/*==============================================================*/
create table FOOD (
   FOODNAME             char(100)            not null,
   STAFFID              char(50)             not null,
   FOODEXPIREDDATE      datetime             null,
   MANUFACTUREDATE      datetime             null,
   FOODCOST             int                  null,
   constraint PK_FOOD primary key nonclustered (FOODNAME)
)
go

/*==============================================================*/
/* Index: ORDER_CHEF_FK                                         */
/*==============================================================*/
create index ORDER_CHEF_FK on FOOD (
STAFFID ASC
)
go

/*==============================================================*/
/* Table: FOODORDER                                             */
/*==============================================================*/
create table FOODORDER (
   SERVICEID            char(30)             not null,
   IDENTIFICATION       char(50)             not null,
   PAID                 bit                  null,
   constraint PK_FOODORDER primary key nonclustered (SERVICEID)
)
go

/*==============================================================*/
/* Index: CUSTOMER_SERVICE_FK                                   */
/*==============================================================*/
create index CUSTOMER_SERVICE_FK on FOODORDER (
IDENTIFICATION ASC
)
go

/*==============================================================*/
/* Table: INVOICE                                               */
/*==============================================================*/
create table INVOICE (
   IDENTIFICATION       char(50)             null,
   SERVICEID            char(30)             not null,
   STAFFID              char(50)             not null,
   TIMEINVOICE          datetime             null,
   COSTINVOICE          int                  null
)
go

/*==============================================================*/
/* Index: CUSTOMER_INVOICE_FK                                   */
/*==============================================================*/
create index CUSTOMER_INVOICE_FK on INVOICE (
IDENTIFICATION ASC
)
go

/*==============================================================*/
/* Index: INVOICE_RECEPTIONIST_FK                               */
/*==============================================================*/
create index INVOICE_RECEPTIONIST_FK on INVOICE (
STAFFID ASC
)
go

/*==============================================================*/
/* Index: INVOICE_SERVICE2_FK                                   */
/*==============================================================*/
create index INVOICE_SERVICE2_FK on INVOICE (
SERVICEID ASC
)
go

/*==============================================================*/
/* Table: OPERATINGCOST                                         */
/*==============================================================*/
create table OPERATINGCOST (
   CODE                 int                  not null,
   BRANCHID             char(50)             null,
   COSTOPERATION        int                  null,
   TYPEOPERATION        char(100)            null,
   constraint PK_OPERATINGCOST primary key nonclustered (CODE)
)
go

/*==============================================================*/
/* Index: BRANCH_OPERATIONCOST_FK                               */
/*==============================================================*/
create index BRANCH_OPERATIONCOST_FK on OPERATINGCOST (
BRANCHID ASC
)
go

/*==============================================================*/
/* Table: RECEPTIONIST                                          */
/*==============================================================*/
create table RECEPTIONIST (
   STAFFID              char(50)             not null,
   BRANCHID             char(50)             not null,
   MNGID                char(50)             not null,
   ADDRESSSTAFF         char(200)            null,
   NAMESTAFF            char(50)             null,
   AGESTAFF             int                  null,
   STARTINGDATE         datetime             null,
   SALARY               int                  null,
   POSSITION            char(50)             null,
   STAFFGENDER          bit                  null,
   constraint PK_RECEPTIONIST primary key nonclustered (STAFFID)
)
go

/*==============================================================*/
/* Table: REGISTER                                              */
/*==============================================================*/
create table REGISTER (
   USERNAME             char(30)             not null,
   STAFFID              char(50)             not null,
   PASSWORD             char(30)             null,
   constraint PK_REGISTER primary key nonclustered (USERNAME)
)
go

/*==============================================================*/
/* Index: STAFF_REGISTER2_FK                                    */
/*==============================================================*/
create index STAFF_REGISTER2_FK on REGISTER (
STAFFID ASC
)
go

/*==============================================================*/
/* Table: RENTEDROOM                                            */
/*==============================================================*/
create table RENTEDROOM (
   SERVICEID            char(30)             not null,
   STAFFID              char(50)             not null,
   ROOMDID              int                  not null,
   CHECKINDATE          datetime             null,
   CHECKOUTDATE         datetime             null,
   constraint PK_RENTEDROOM primary key nonclustered (SERVICEID, STAFFID, ROOMDID)
)
go

/*==============================================================*/
/* Index: CONTAIN2_FK                                           */
/*==============================================================*/
create index CONTAIN2_FK on RENTEDROOM (
SERVICEID ASC
)
go

/*==============================================================*/
/* Index: ASSIGN_FK                                             */
/*==============================================================*/
create index ASSIGN_FK on RENTEDROOM (
STAFFID ASC
)
go

/*==============================================================*/
/* Index: ASSIGNED_TO_FK                                        */
/*==============================================================*/
create index ASSIGNED_TO_FK on RENTEDROOM (
ROOMDID ASC
)
go

/*==============================================================*/
/* Table: RESERVATION                                           */
/*==============================================================*/
create table RESERVATION (
   SERVICEID            char(30)             not null,
   IDENTIFICATION       char(50)             not null,
   PAID                 bit                  null,
   constraint PK_RESERVATION primary key nonclustered (SERVICEID)
)
go

/*==============================================================*/
/* Index: CUSTOMER_SERVICE2_FK                                  */
/*==============================================================*/
create index CUSTOMER_SERVICE2_FK on RESERVATION (
IDENTIFICATION ASC
)
go

/*==============================================================*/
/* Table: ROOM                                                  */
/*==============================================================*/
create table ROOM (
   ROOMDID              int                  not null,
   BRANCHID             char(50)             not null,
   STATUS               bit                  null,
   ROOMTYPE             char(50)             null,
   MAINTAIN             bit                  null,
   ROOMCOST             int                  null,
   ROOMNUMBER           int                  null,
   constraint PK_ROOM primary key nonclustered (ROOMDID)
)
go

/*==============================================================*/
/* Index: BRANCH_ROOM_FK                                        */
/*==============================================================*/
create index BRANCH_ROOM_FK on ROOM (
BRANCHID ASC
)
go

/*==============================================================*/
/* Table: STAFF                                                 */
/*==============================================================*/
create table STAFF (
   STAFFID              char(50)             not null,
   BRANCHID             char(50)             not null,
   MNGID                char(50)             null,
   ADDRESSSTAFF         char(200)            null,
   NAMESTAFF            char(50)             null,
   AGESTAFF             int                  null,
   STARTINGDATE         datetime             null,
   SALARY               int                  null,
   POSSITION            char(50)             null,
   STAFFGENDER          bit                  null,
   constraint PK_STAFF primary key nonclustered (STAFFID)
)
go

/*==============================================================*/
/* Index: BRANCH_STAFF_FK                                       */
/*==============================================================*/
create index BRANCH_STAFF_FK on STAFF (
BRANCHID ASC
)
go

/*==============================================================*/
/* Index: MANAGER_FK                                            */
/*==============================================================*/
create index MANAGER_FK on STAFF (
MNGID ASC
)
go

/*==============================================================*/
/* Table: USINGFOOD                                             */
/*==============================================================*/
create table USINGFOOD (
   SERVICEID            char(30)             not null,
   STAFFID              char(50)             not null,
   FOODNAME             char(100)            not null,
   TIME                 datetime             null,
   constraint PK_USINGFOOD primary key nonclustered (SERVICEID, STAFFID, FOODNAME)
)
go

/*==============================================================*/
/* Index: CONTAIN3_FK                                           */
/*==============================================================*/
create index CONTAIN3_FK on USINGFOOD (
SERVICEID ASC
)
go

/*==============================================================*/
/* Index: CONTAIN_FK                                            */
/*==============================================================*/
create index CONTAIN_FK on USINGFOOD (
FOODNAME ASC
)
go

/*==============================================================*/
/* Index: SERVED_FK                                             */
/*==============================================================*/
create index SERVED_FK on USINGFOOD (
STAFFID ASC
)
go

alter table CHEF
   add constraint FK_CHEF_INHERITAN_STAFF foreign key (STAFFID)
      references STAFF (STAFFID)
go

alter table CLEANER
   add constraint FK_CLEANER_INHERITAN_STAFF foreign key (STAFFID)
      references STAFF (STAFFID)
go

alter table CLEANER_ROOM
   add constraint FK_CLEANER__CLEANER_R_ROOM foreign key (ROOMDID)
      references ROOM (ROOMDID)
go

alter table CLEANER_ROOM
   add constraint FK_CLEANER__CLEANER_R_CLEANER foreign key (STAFFID)
      references CLEANER (STAFFID)
go

alter table FOOD
   add constraint FK_FOOD_ORDER_CHE_CHEF foreign key (STAFFID)
      references CHEF (STAFFID)
go

alter table FOODORDER
   add constraint FK_FOODORDE_CUSTOMER__CUSTOMER foreign key (IDENTIFICATION)
      references CUSTOMER (IDENTIFICATION)
go

alter table INVOICE
   add constraint FK_INVOICE_CUSTOMER__CUSTOMER foreign key (IDENTIFICATION)
      references CUSTOMER (IDENTIFICATION)
go

alter table INVOICE
   add constraint FK_INVOICE_INVOICE_R_RECEPTIO foreign key (STAFFID)
      references RECEPTIONIST (STAFFID)
go

alter table INVOICE
   add constraint FK_INVOICE_INVOICE_S_FOODORDE foreign key (SERVICEID)
      references FOODORDER (SERVICEID)
go

alter table INVOICE
   add constraint FK_INVOICE_INVOICE_S_RESERVAT foreign key (SERVICEID)
      references RESERVATION (SERVICEID)
go

alter table OPERATINGCOST
   add constraint FK_OPERATIN_BRANCH_OP_BRANCH foreign key (BRANCHID)
      references BRANCH (BRANCHID)
go

alter table RECEPTIONIST
   add constraint FK_RECEPTIO_INHERITAN_STAFF foreign key (STAFFID)
      references STAFF (STAFFID)
go

alter table REGISTER
   add constraint FK_REGISTER_STAFF_REG_STAFF foreign key (STAFFID)
      references STAFF (STAFFID)
go

alter table RENTEDROOM
   add constraint FK_RENTEDRO_ASSIGN_RECEPTIO foreign key (STAFFID)
      references RECEPTIONIST (STAFFID)
go

alter table RENTEDROOM
   add constraint FK_RENTEDRO_ASSIGNED__ROOM foreign key (ROOMDID)
      references ROOM (ROOMDID)
go

alter table RENTEDROOM
   add constraint FK_RENTEDRO_CONTAIN2_RESERVAT foreign key (SERVICEID)
      references RESERVATION (SERVICEID)
go

alter table RESERVATION
   add constraint FK_RESERVAT_CUSTOMER__CUSTOMER foreign key (IDENTIFICATION)
      references CUSTOMER (IDENTIFICATION)
go

alter table ROOM
   add constraint FK_ROOM_BRANCH_RO_BRANCH foreign key (BRANCHID)
      references BRANCH (BRANCHID)
go

alter table STAFF
   add constraint FK_STAFF_BRANCH_ST_BRANCH foreign key (BRANCHID)
      references BRANCH (BRANCHID)
go

alter table STAFF
   add constraint FK_STAFF_MANAGER_STAFF foreign key (MNGID)
      references STAFF (STAFFID)
go

alter table USINGFOOD
   add constraint FK_USINGFOO_CONTAIN_FOOD foreign key (FOODNAME)
      references FOOD (FOODNAME)
go

alter table USINGFOOD
   add constraint FK_USINGFOO_CONTAIN3_FOODORDE foreign key (SERVICEID)
      references FOODORDER (SERVICEID)
go

alter table USINGFOOD
   add constraint FK_USINGFOO_SERVED_RECEPTIO foreign key (STAFFID)
      references RECEPTIONIST (STAFFID)
go

