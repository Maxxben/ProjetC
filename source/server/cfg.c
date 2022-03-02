#include <stdio.h>
#include <stdlib.h>
#include <libconfig.h>
#include "../common/cfg.h"
 
cfgServer initCfgSrv()
{
  config_t cfg;
  config_init(&cfg);
 
  if(! config_read_file(&cfg, "config/server.cfg"))
  {
    fprintf(stderr, "%s:%d - %s\n", config_error_file(&cfg),config_error_line(&cfg), config_error_text(&cfg));
    config_destroy(&cfg);
  }
 
  const char *server_IP;
  int server_Port = 0;
  config_lookup_string(&cfg, "server_IP", &server_IP);
  config_lookup_int(&cfg, "server_Port", &server_Port);
 
  cfgServer cfgServer;
  cfgServer.server_IP = server_IP;
  cfgServer.server_Port = server_Port;
 
  return cfgServer;
}
 

void afficheConfigSrv(cfgServer cfg)
{
    printf("\nConfig du serveur :\n IP du serveur : %s \nPort du serveur : %d\n", cfg.server_IP, cfg.server_Port);
}