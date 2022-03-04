/* 
 * File:   cfg.c
 * Author: Maxxben
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <libconfig.h>
#include "../common/cfg.h"


/**
* @brief Initialisation de la config du serveur
*/
cfgServer initCfgSrv()
{
  config_t cfg;
  config_init(&cfg);

  //Si erreur dans le fichier de config
  if(! config_read_file(&cfg, "config/server.cfg"))
  {
    fprintf(stderr, "%s:%d - %s\n", config_error_file(&cfg),config_error_line(&cfg), config_error_text(&cfg));
    config_destroy(&cfg);
  }
 
  const char *server_IP;
  int server_Port = 0;
  const char *room_name;
  int room_start_balance = 0;
  int room_client_1 = 0;
  int room_client_2 = 0;

  config_lookup_string(&cfg, "server_IP", &server_IP);
  config_lookup_int(&cfg, "server_Port", &server_Port);
  config_lookup_string(&cfg, "room_name", &room_name);
  config_lookup_int(&cfg, "room_start_balance", &room_start_balance);
  config_lookup_int(&cfg, "room_client_1", &room_client_1);
  config_lookup_int(&cfg, "room_client_2", &room_client_2);

  cfgServer cfgServer;
  cfgServer.server_IP = server_IP;
  cfgServer.server_Port = server_Port;
  cfgServer.room_name = room_name;
  cfgServer.room_start_balance = room_start_balance;
  cfgServer.room_client_1 = room_client_1;
  cfgServer.room_client_2 = room_client_2;
 
  return cfgServer;
}

/**
* @brief Affichage de la config du serveur
* @param cfg strcture config serveur
*/
void afficherConfigSrv(cfgServer cfg)
{
    printf("\n--- Config du serveur : ---\nIP du serveur : %s \nPort du serveur : %d\n\nNom de la partie : %s\nBank de depart : %d\nId client 1 : %d\nId client 2 : %d\n\n", cfg.server_IP, cfg.server_Port, cfg.room_name, cfg.room_start_balance, cfg.room_client_1, cfg.room_client_2);
}