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
 

void showServerConfig(cfgServer cfg)
{
    printf("\n--------------------------\n SERVER CONFIGURATION\n \n - IP Address: %s \n\033[1;37m - Port: %d \n--------------------------\n", cfg.server_IP, cfg.server_Port);
}