NAME=Inception

PATH_VOLUME_DB=/home/arthur/inception/db_data
PATH_VOLUME_WP=/home/arthur/inception/wp_data

all   : compose

compose	: message_compose
	mkdir -p $(PATH_VOLUME_WP)
	mkdir -p $(PATH_VOLUME_DB)
	docker-compose -f ./srcs/docker-compose.yml build
	docker-compose -f ./srcs/docker-compose.yml up

down	: message_down
	docker-compose -f ./srcs/docker-compose.yml down

prune	: message_prune down
	docker system prune -a -f
	rm -rf $(PATH_VOLUME_WP)
	rm -rf $(PATH_VOLUME_DB)
	docker volume rm wp_volume db_volume

stop	: message_stop
	docker-compose -f ./srcs/docker-compose.yml stop

start	:	message_start
	docker-compose -f ./srcs/docker-compose.yml start

message_compose:
	@echo "EXECUTION	: $(COLOUR_RED) [compose]\n$(NO_COLOUR)"

message_down:
	@echo "EXECUTION	: $(COLOUR_RED) [down]\n$(NO_COLOUR)"

message_prune:
	@echo "EXECUTION	: $(COLOUR_RED) [prune]\n$(NO_COLOUR)"

message_stop:
	@echo "EXECUTION	: $(COLOUR_RED) [stop]\n$(NO_COLOUR)"

message_start:
	@echo "EXECUTION	: $(COLOUR_RED) [start]\n$(NO_COLOUR)"

# colors

COLOUR_RED		= \033[31m
COLOUR_YELLOW	= \033[33m
COLOUR_BLUE		= \033[34m
COLOUR_GREEN	= \033[32m
NO_COLOUR		= \033[0m