/* 
 * File:   cfg.c
 * Author: Maxxben
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <libconfig.h>
#include <string.h>
#include "../common/cfg.h"

/**
* @brief Initialisation de la config du client
*/
cfgClient initCfgCli(){
  config_t cfg;
  config_init(&cfg);

  //Si erreur dans le fichier de config
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

/**
* @brief Affichage de la config du client
* @param cfg strcture config serveur
*/
void afficherConfigCli(cfgClient cfg){
  printf("\n--- Config du client ---\n \nIP du serveur \t: %s \nPort serveur \t: %d\nID du client \t: %d\n\n", cfg.server_IP, cfg.server_Port, cfg.id_Client);
}