//
// Created by Stefanos Mitropoulos on 2019-05-20.
//


#include "MessageWriter_TCP.h"

int sendData (int fd, void *data, int len)
{
  char *pdata = (char *) data;

  if (pdata[0] != 0)
    {
      while (len > 0)
        {
          int rv = send (fd, pdata, len, 0);
          if (rv < 0)
            {
              if (errno != EWOULDBLOCK)
                return rv;
              break;
            }

          pdata += rv;
          len -= rv;
        }
    }

  if (len > 0)
    {
      // add pdata up to len bytes to fd's buffer...
      bzero (data, sizeof (data));
      strcpy ((char *) data, pdata);

    }

  return 0;
}

void MessageWriter_TCP::sendMessage (int sockfd) const
{
#define MAX 256

  if (!sockfd)
    {
      sockfd = mSocket;
    }

  char buff[MAX];

  struct pollfd fds[1];
  fds[0].fd = sockfd;
  fds[0].events = (POLLIN);
  int rv{};

  while (true)
    {
      if ((rv = poll (fds, 1, 100) > 0))
        {
          if (fds[0].revents & POLLIN)
            {
              rv = recv (sockfd, buff, 200, 0);
              if (rv <= 0) break;
              std::cout << "From Server " << buff << std::endl;

              if (buff[rv - 1] == '\n') // MAY take multiple reads!
                {
                  bzero (buff, sizeof (buff));
                  strcpy (buff, "HELLO WORLD");
                  std::cout << "From Client " << buff << std::endl;
                  sendData (sockfd, buff, strlen (buff));
                }
            }

          if (fds[0].revents & POLLOUT)
            {
              char *pdata = buff; // fd's buffer data
              int len = sizeof (buff); // fd's buffer length
              int sent = 0;

              while (len > 0)
                {
                  rv = send (sockfd, pdata, len, 0);
                  if (rv < 0)
                    break;

                  pdata += rv;
                  len -= rv;
                  sent += rv;
                }

              if (sent > 0)
                {
                  // remove sent bytes from fd's buffer...
                }
            }
        }
    }

  close (sockfd);

  std::cout << "Reply from the server: " << buff << std::endl;

}