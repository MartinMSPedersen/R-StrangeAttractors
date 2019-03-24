\name{StrangeAttractors-package}
\alias{StrangeAttractors-package}
\alias{StrangeAttractors}
\docType{package}
\title{
  This packages computes several Strange Attractors.
}
\description{
  This packages computes several Strange Attractors using fast C++-code.
  An attractor is called strange if it has a fractal structure. This is often the case when the dynamics on it are chaotic.
}
\details{
}
\author{
Maintainer: Martin M. S. Pedersen <martin@linux.com>
}
\references{
}
\keyword{ package }
\seealso{
}
\examples{
  \dontrun{
        df <- Clifford(-1.4, 1.6, 1.0, 0.7)
        png("clifford.png", units="px", width=1200, height=1200, res=300)

        opt = theme(legend.position  = "none",
          panel.background = element_rect(fill="white"),
          axis.ticks       = element_blank(),
          panel.grid       = element_blank(),
          axis.title       = element_blank(),
          axis.text        = element_blank())
        ggplot2::ggplot(df, aes(x, y)) + geom_point(color = "black", shape = 46, alpha = 0.1) + opt
        dev.off()
  }

  \dontrun{
        library(magrittr)
        library(dplyr)
        library(ggplot2)

        df <- sprott()
        mx <- quantile(df$x, probs = 0.05)
        Mx <- quantile(df$x, probs = 0.95)
        my <- quantile(df$y, probs = 0.05)
        My <- quantile(df$y, probs = 0.95)

        df  <- df %>% filter(x > mx, x < Mx, y > my, y < My) 
        plot <- ggplot(df) +
                geom_point(aes(x, y), shape=46, alpha=0.01, size=0, color="black") +
                scale_x_continuous(expand = c(0,0))+
                scale_y_continuous(expand = c(0,0))+
                coord_fixed() +
                theme(legend.position  = "none",
                      panel.background = element_rect(fill="white", color="black"),
                      plot.background  = element_rect(fill="white"),
                      axis.ticks       = element_blank(),
                      panel.grid       = element_blank(),
                      axis.title       = element_blank(),
                      axis.text        = element_blank())
        png("sprott.png", units="px", width=2400, height=2400, res=300)
        print(plot)
        dev.off()
  }
}

