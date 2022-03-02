#include <stdio.h>
#include <stdlib.h>
#include <libconfig.h>
#include <string.h>
#include "cfg.h"

/**
* @brief Initialisation config client
*/
cfgClient initCfg(){
  config_t cfg;
  config_init(&cfg);

  if(! config_read_file(&cfg, "config/client.cfg")){
    fprintf(stderr, "%s:%d - %s\n", config_error_file(&cfg),config_error_line(&cfg), config_error_text(&cfg));
    config_destroy(&cfg);
  }
 
  const char *server_IP;
  int server_Port = 0;
  int id_Client = 0;

  config_lookup_string(&cfg, "server_IP", &server_IP);
  config_lookup_int(&cfg, "server_Port", &server_Port);
  config_lookup_int(&cfg, "id_Client", &id_Client);

  cfgClient cfgClient;
  strcpy(cfgClient.server_IP, server_IP);
  cfgClient.server_Port = server_Port;
  cfgClient.id_Client = id_Client;

  return cfgClient;
}

void showcfgClient(cfgClient cfg){
  printf("\n--- CONFIGURATION DU CLIENT ---\n \nIP du serveur : %s \nPort du serveur : %d \nID du client : %d\n", cfg.server_IP, cfg.server_Port, cfg.id_Client);
}