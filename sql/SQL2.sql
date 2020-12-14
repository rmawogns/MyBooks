

create table author (
	ID int primary key,
	name varchar(20),
	phone varchar(15),
	e_mail varchar(50),
	sns varchar(50)
);

create table publisher (
	ID int primary key,
	name varchar(20),
	phone varchar(50),
	e_mail varchar(50),
	address varchar(80)
);

create table book (
	ID int primary key,
	book_title varchar(50),
	book_price int,
	author_ID int,
	publisher_ID int,
	foreign key(ID) references author(ID),
	foreign key(ID) references publisher(ID)
)ENGINE=InnoDB;
